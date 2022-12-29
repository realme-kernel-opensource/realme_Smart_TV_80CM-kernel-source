// SPDX-License-Identifier: (GPL-2.0 OR BSD-3-Clause)
// Copyright(c) 2015-18 Intel Corporation.

/*
 *  stream.c - SoundWire Bus stream operations.
 */

#include <linux/delay.h>
#include <linux/device.h>
#include <linux/init.h>
#include <linux/module.h>
#include <linux/mod_devicetable.h>
#include <linux/slab.h>
#include <linux/soundwire/sdw_registers.h>
#include <linux/soundwire/sdw.h>
#include "bus.h"

/*
 * Array of supported rows and columns as per MIPI SoundWire Specification 1.1
 *
 * The rows are arranged as per the array index value programmed
 * in register. The index 15 has dummy value 0 in order to fill hole.
 */
int rows[SDW_FRAME_ROWS] = {48, 50, 60, 64, 75, 80, 125, 147,
			96, 100, 120, 128, 150, 160, 250, 0,
			192, 200, 240, 256, 72, 144, 90, 180};

int cols[SDW_FRAME_COLS] = {2, 4, 6, 8, 10, 12, 14, 16};

static int sdw_find_col_index(int col)
{
	int i;

	for (i = 0; i < SDW_FRAME_COLS; i++) {
		if (cols[i] == col)
			return i;
	}

	pr_warn("Requested column not found, selecting lowest column no: 2\n");
	return 0;
}

static int sdw_find_row_index(int row)
{
	int i;

	for (i = 0; i < SDW_FRAME_ROWS; i++) {
		if (rows[i] == row)
			return i;
	}

	pr_warn("Requested row not found, selecting lowest row no: 48\n");
	return 0;
}
static int _sdw_program_slave_port_params(struct sdw_bus *bus,
				struct sdw_slave *slave,
				struct sdw_transport_params *t_params,
				enum sdw_dpn_type type)
{
	u32 addr1, addr2, addr3, addr4;
	int ret;
	u16 wbuf;

	if (bus->params.next_bank) {
		addr1 = SDW_DPN_OFFSETCTRL2_B1(t_params->port_num);
		addr2 = SDW_DPN_BLOCKCTRL3_B1(t_params->port_num);
		addr3 = SDW_DPN_SAMPLECTRL2_B1(t_params->port_num);
		addr4 = SDW_DPN_HCTRL_B1(t_params->port_num);
	} else {
		addr1 = SDW_DPN_OFFSETCTRL2_B0(t_params->port_num);
		addr2 = SDW_DPN_BLOCKCTRL3_B0(t_params->port_num);
		addr3 = SDW_DPN_SAMPLECTRL2_B0(t_params->port_num);
		addr4 = SDW_DPN_HCTRL_B0(t_params->port_num);
	}

	/* Program DPN_OffsetCtrl2 registers */
	ret = sdw_write(slave, addr1, t_params->offset2);
	if (ret < 0) {
		dev_err(bus->dev, "DPN_OffsetCtrl2 register write failed");
		return ret;
	}

	/* Program DPN_BlockCtrl3 register */
	ret = sdw_write(slave, addr2, t_params->blk_pkg_mode);
	if (ret < 0) {
		dev_err(bus->dev, "DPN_BlockCtrl3 register write failed");
		return ret;
	}

	/*
	 * Data ports are FULL, SIMPLE and REDUCED. This function handles
	 * FULL and REDUCED only and and beyond this point only FULL is
	 * handled, so bail out if we are not FULL data port type
	 */
	if (type != SDW_DPN_FULL)
		return ret;

	/* Program DPN_SampleCtrl2 register */
	wbuf = (t_params->sample_interval - 1);
	wbuf &= SDW_DPN_SAMPLECTRL_HIGH;
	wbuf >>= SDW_REG_SHIFT(SDW_DPN_SAMPLECTRL_HIGH);

	ret = sdw_write(slave, addr3, wbuf);
	if (ret < 0) {
		dev_err(bus->dev, "DPN_SampleCtrl2 register write failed");
		return ret;
	}

	/* Program DPN_HCtrl register */
	wbuf = t_params->hstart;
	wbuf <<= SDW_REG_SHIFT(SDW_DPN_HCTRL_HSTART);
	wbuf |= t_params->hstop;

	ret = sdw_write(slave, addr4, wbuf);
	if (ret < 0)
		dev_err(bus->dev, "DPN_HCtrl register write failed");

	return ret;
}

static int sdw_program_slave_port_params(struct sdw_bus *bus,
			struct sdw_slave_runtime *s_rt,
			struct sdw_port_runtime *p_rt)
{
	struct sdw_transport_params *t_params = &p_rt->transport_params;
	struct sdw_port_params *p_params = &p_rt->port_params;
	struct sdw_slave_prop *slave_prop = &s_rt->slave->prop;
	u32 addr1, addr2, addr3, addr4, addr5, addr6;
	struct sdw_dpn_prop *dpn_prop;
	int ret;
	u8 wbuf;

	dpn_prop = sdw_get_slave_dpn_prop(s_rt->slave,
					s_rt->direction,
					t_params->port_num);
	if (!dpn_prop)
		return -EINVAL;

	addr1 = SDW_DPN_PORTCTRL(t_params->port_num);
	addr2 = SDW_DPN_BLOCKCTRL1(t_params->port_num);

	if (bus->params.next_bank) {
		addr3 = SDW_DPN_SAMPLECTRL1_B1(t_params->port_num);
		addr4 = SDW_DPN_OFFSETCTRL1_B1(t_params->port_num);
		addr5 = SDW_DPN_BLOCKCTRL2_B1(t_params->port_num);
		addr6 = SDW_DPN_LANECTRL_B1(t_params->port_num);

	} else {
		addr3 = SDW_DPN_SAMPLECTRL1_B0(t_params->port_num);
		addr4 = SDW_DPN_OFFSETCTRL1_B0(t_params->port_num);
		addr5 = SDW_DPN_BLOCKCTRL2_B0(t_params->port_num);
		addr6 = SDW_DPN_LANECTRL_B0(t_params->port_num);
	}

	/* Program DPN_PortCtrl register */
	wbuf = p_params->data_mode << SDW_REG_SHIFT(SDW_DPN_PORTCTRL_DATAMODE);
	wbuf |= p_params->flow_mode;

	ret = sdw_update(s_rt->slave, addr1, 0xF, wbuf);
	if (ret < 0) {
		dev_err(&s_rt->slave->dev,
			"DPN_PortCtrl register write failed for port %d",
			t_params->port_num);
		return ret;
	}

	/* Program DPN_BlockCtrl1 register */
	ret = sdw_write(s_rt->slave, addr2, (p_params->bps - 1));
	if (ret < 0) {
		dev_err(&s_rt->slave->dev,
			"DPN_BlockCtrl1 register write failed for port %d",
			t_params->port_num);
		return ret;
	}

	/* Program DPN_SampleCtrl1 register */
	wbuf = (t_params->sample_interval - 1) & SDW_DPN_SAMPLECTRL_LOW;
	ret = sdw_write(s_rt->slave, addr3, wbuf);
	if (ret < 0) {
		dev_err(&s_rt->slave->dev,
			"DPN_SampleCtrl1 register write failed for port %d",
			t_params->port_num);
		return ret;
	}

	/* Program DPN_OffsetCtrl1 registers */
	ret = sdw_write(s_rt->slave, addr4, t_params->offset1);
	if (ret < 0) {
		dev_err(&s_rt->slave->dev,
			"DPN_OffsetCtrl1 register write failed for port %d",
			t_params->port_num);
		return ret;
	}

	/* Program DPN_BlockCtrl2 register*/
	if (t_params->blk_grp_ctrl_valid) {
		ret = sdw_write(s_rt->slave, addr5, t_params->blk_grp_ctrl);
		if (ret < 0) {
			dev_err(&s_rt->slave->dev,
				"DPN_BlockCtrl2 reg write failed for port %d",
				t_params->port_num);
			return ret;
		}
	}

	/* program DPN_LaneCtrl register */
	if (slave_prop->lane_control_support) {
		ret = sdw_write(s_rt->slave, addr6, t_params->lane_ctrl);
		if (ret < 0) {
			dev_err(&s_rt->slave->dev,
				"DPN_LaneCtrl register write failed for port %d",
				t_params->port_num);
			return ret;
		}
	}

	if (dpn_prop->type != SDW_DPN_SIMPLE) {
		ret = _sdw_program_slave_port_params(bus, s_rt->slave,
						t_params, dpn_prop->type);
		if (ret < 0)
			dev_err(&s_rt->slave->dev,
				"Transport reg write failed for port: %d",
				t_params->port_num);
	}

	return ret;
}

static int sdw_program_master_port_params(struct sdw_bus *bus,
		struct sdw_port_runtime *p_rt)
{
	int ret;

	/*
	 * we need to set transport and port parameters for the port.
	 * Transport parameters refers to the smaple interval, offsets and
	 * hstart/stop etc of the data. Port parameters refers to word
	 * length, flow mode etc of the port
	 */
	ret = bus->port_ops->dpn_set_port_transport_params(bus,
					&p_rt->transport_params,
					bus->params.next_bank);
	if (ret < 0)
		return ret;

	return bus->port_ops->dpn_set_port_params(bus,
				&p_rt->port_params,
				bus->params.next_bank);
}

/**
 * sdw_program_port_params() - Programs transport parameters of Master(s)
 * and Slave(s)
 *
 * @m_rt: Master stream runtime
 */
static int sdw_program_port_params(struct sdw_master_runtime *m_rt)
{
	struct sdw_slave_runtime *s_rt = NULL;
	struct sdw_bus *bus = m_rt->bus;
	struct sdw_port_runtime *p_rt;
	int ret = 0;

	/* Program transport & port parameters for Slave(s) */
	list_for_each_entry(s_rt, &m_rt->slave_rt_list, m_rt_node) {
		list_for_each_entry(p_rt, &s_rt->port_list, port_node) {
			ret = sdw_program_slave_port_params(bus, s_rt, p_rt);
			if (ret < 0)
				return ret;
		}
	}

	/* Program transport & port parameters for Master(s) */
	list_for_each_entry(p_rt, &m_rt->port_list, port_node) {
		ret = sdw_program_master_port_params(bus, p_rt);
		if (ret < 0)
			return ret;
	}

	return 0;
}

/**
 * sdw_enable_disable_slave_ports: Enable/disable slave data port
 *
 * @bus: bus instance
 * @s_rt: slave runtime
 * @p_rt: port runtime
 * @en: enable or disable operation
 *
 * This function only sets the enable/disable bits in the relevant bank, the
 * actual enable/disable is done with a bank switch
 */
static int sdw_enable_disable_slave_ports(struct sdw_bus *bus,
				struct sdw_slave_runtime *s_rt,
				struct sdw_port_runtime *p_rt, bool en)
{
	struct sdw_transport_params *t_params = &p_rt->transport_params;
	u32 addr;
	int ret;

	if (bus->params.next_bank)
		addr = SDW_DPN_CHANNELEN_B1(p_rt->num);
	else
		addr = SDW_DPN_CHANNELEN_B0(p_rt->num);

	/*
	 * Since bus doesn't support sharing a port across two streams,
	 * it is safe to reset this register
	 */
	if (en)
		ret = sdw_update(s_rt->slave, addr, 0xFF, p_rt->ch_mask);
	else
		ret = sdw_update(s_rt->slave, addr, 0xFF, 0x0);

	if (ret < 0)
		dev_err(&s_rt->slave->dev,
			"Slave chn_en reg write failed:%d port:%d",
			ret, t_params->port_num);

	return ret;
}

static int sdw_enable_disable_master_ports(struct sdw_master_runtime *m_rt,
			struct sdw_port_runtime *p_rt, bool en)
{
	struct sdw_transport_params *t_params = &p_rt->transport_params;
	struct sdw_bus *bus = m_rt->bus;
	struct sdw_enable_ch enable_ch;
	int ret = 0;

	enable_ch.port_num = p_rt->num;
	enable_ch.ch_mask = p_rt->ch_mask;
	enable_ch.enable = en;

	/* Perform Master port channel(s) enable/disable */
	if (bus->port_ops->dpn_port_enable_ch) {
		ret = bus->port_ops->dpn_port_enable_ch(bus,
				&enable_ch, bus->params.next_bank);
		if (ret < 0) {
			dev_err(bus->dev,
				"Master chn_en write failed:%d port:%d",
				ret, t_params->port_num);
			return ret;
		}
	} else {
		dev_err(bus->dev,
			"dpn_port_enable_ch not supported, %s failed\n",
			en ? "enable" : "disable");
		return -EINVAL;
	}

	return 0;
}

/**
 * sdw_enable_disable_ports() - Enable/disable port(s) for Master and
 * Slave(s)
 *
 * @m_rt: Master stream runtime
 * @en: mode (enable/disable)
 */
static int sdw_enable_disable_ports(struct sdw_master_runtime *m_rt, bool en)
{
	struct sdw_port_runtime *s_port, *m_port;
	struct sdw_slave_runtime *s_rt = NULL;
	int ret = 0;

	/* Enable/Disable Slave port(s) */
	list_for_each_entry(s_rt, &m_rt->slave_rt_list, m_rt_node) {
		list_for_each_entry(s_port, &s_rt->port_list, port_node) {
			ret = sdw_enable_disable_slave_ports(m_rt->bus, s_rt,
							s_port, en);
			if (ret < 0)
				return ret;
		}
	}

	/* Enable/Disable Master port(s) */
	list_for_each_entry(m_port, &m_rt->port_list, port_node) {
		ret = sdw_enable_disable_master_ports(m_rt, m_port, en);
		if (ret < 0)
			return ret;
	}

	return 0;
}

static int sdw_do_port_prep(struct sdw_slave_runtime *s_rt,
		struct sdw_prepare_ch prep_ch, enum sdw_port_prep_ops cmd)
{
	const struct sdw_slave_ops *ops = s_rt->slave->ops;
	int ret;

	if (ops->port_prep) {
		ret = ops->port_prep(s_rt->slave, &prep_ch, cmd);
		if (ret < 0) {
			dev_err(&s_rt->slave->dev,
				"Slave Port Prep cmd %d failed: %d", cmd, ret);
			return ret;
		}
	}

	return 0;
}

static int sdw_prep_deprep_slave_ports(struct sdw_bus *bus,
			struct sdw_slave_runtime *s_rt,
			struct sdw_port_runtime *p_rt, bool prep)
{
	struct completion *port_ready = NULL;
	struct sdw_dpn_prop *dpn_prop;
	struct sdw_prepare_ch prep_ch;
	unsigned int time_left;
	bool intr = false;
	int ret = 0, val;
	u32 addr;

	prep_ch.num = p_rt->num;
	prep_ch.ch_mask = p_rt->ch_mask;

	dpn_prop = sdw_get_slave_dpn_prop(s_rt->slave,
					s_rt->direction,
					prep_ch.num);
	if (!dpn_prop) {
		dev_err(bus->dev,
			"Slave Port:%d properties not found", prep_ch.num);
		return -EINVAL;
	}

	prep_ch.prepare = prep;

	prep_ch.bank = bus->params.next_bank;

	if (dpn_prop->device_interrupts || !dpn_prop->simple_ch_prep_sm)
		intr = true;

	/*
	 * Enable interrupt before Port prepare.
	 * For Port de-prepare, it is assumed that port
	 * was prepared earlier
	 */
	if (prep && intr) {
		ret = sdw_configure_dpn_intr(s_rt->slave, p_rt->num, prep,
						dpn_prop->device_interrupts);
		if (ret < 0)
			return ret;
	}

	/* Inform slave about the impending port prepare */
	sdw_do_port_prep(s_rt, prep_ch, SDW_OPS_PORT_PRE_PREP);

	/* Prepare Slave port implementing CP_SM */
	if (!dpn_prop->simple_ch_prep_sm) {
		addr = SDW_DPN_PREPARECTRL(p_rt->num);

		if (prep)
			ret = sdw_update(s_rt->slave, addr,
					0xFF, p_rt->ch_mask);
		else
			ret = sdw_update(s_rt->slave, addr, 0xFF, 0x0);

		if (ret < 0) {
			dev_err(&s_rt->slave->dev,
				"Slave prep_ctrl reg write failed");
			return ret;
		}

		/* Wait for completion on port ready */
		port_ready = &s_rt->slave->port_ready[prep_ch.num];
		time_left = wait_for_completion_timeout(port_ready,
				msecs_to_jiffies(dpn_prop->ch_prep_timeout));

		val = sdw_read(s_rt->slave, SDW_DPN_PREPARESTATUS(p_rt->num));
		val &= p_rt->ch_mask;
		if (!time_left || val) {
			dev_err(&s_rt->slave->dev,
				"Chn prep failed for port:%d", prep_ch.num);
			return -ETIMEDOUT;
		}
	}

	/* Inform slaves about ports prepared */
	sdw_do_port_prep(s_rt, prep_ch, SDW_OPS_PORT_POST_PREP);

	/* Disable interrupt after Port de-prepare */
	if (!prep && intr)
		ret = sdw_configure_dpn_intr(s_rt->slave, p_rt->num, prep,
						dpn_prop->device_interrupts);

	return ret;
}

static int sdw_prep_deprep_master_ports(struct sdw_master_runtime *m_rt,
				struct sdw_port_runtime *p_rt, bool prep)
{
	struct sdw_transport_params *t_params = &p_rt->transport_params;
	struct sdw_bus *bus = m_rt->bus;
	const struct sdw_master_port_ops *ops = bus->port_ops;
	struct sdw_prepare_ch prep_ch;
	int ret = 0;

	prep_ch.num = p_rt->num;
	prep_ch.ch_mask = p_rt->ch_mask;
	prep_ch.prepare = prep; /* Prepare/De-prepare */
	prep_ch.bank = bus->params.next_bank;

	/* Pre-prepare/Pre-deprepare port(s) */
	if (ops->dpn_port_prep) {
		ret = ops->dpn_port_prep(bus, &prep_ch);
		if (ret < 0) {
			dev_err(bus->dev, "Port prepare failed for port:%d",
					t_params->port_num);
			return ret;
		}
	}

	return ret;
}

/**
 * sdw_prep_deprep_ports() - Prepare/De-prepare port(s) for Master(s) and
 * Slave(s)
 *
 * @m_rt: Master runtime handle
 * @prep: Prepare or De-prepare
 */
static int sdw_prep_deprep_ports(struct sdw_master_runtime *m_rt, bool prep)
{
	struct sdw_slave_runtime *s_rt = NULL;
	struct sdw_port_runtime *p_rt;
	int ret = 0;

	/* Prepare/De-prepare Slave port(s) */
	list_for_each_entry(s_rt, &m_rt->slave_rt_list, m_rt_node) {
		list_for_each_entry(p_rt, &s_rt->port_list, port_node) {
			ret = sdw_prep_deprep_slave_ports(m_rt->bus, s_rt,
							p_rt, prep);
			if (ret < 0)
				return ret;
		}
	}

	/* Prepare/De-prepare Master port(s) */
	list_for_each_entry(p_rt, &m_rt->port_list, port_node) {
		ret = sdw_prep_deprep_master_ports(m_rt, p_rt, prep);
		if (ret < 0)
			return ret;
	}

	return ret;
}

/**
 * sdw_notify_config() - Notify bus configuration
 *
 * @m_rt: Master runtime handle
 *
 * This function notifies the Master(s) and Slave(s) of the
 * new bus configuration.
 */
static int sdw_notify_config(struct sdw_master_runtime *m_rt)
{
	struct sdw_slave_runtime *s_rt;
	struct sdw_bus *bus = m_rt->bus;
	struct sdw_slave *slave;
	int ret = 0;

	if (bus->ops->set_bus_conf) {
		ret = bus->ops->set_bus_conf(bus, &bus->params);
		if (ret < 0)
			return ret;
	}

	list_for_each_entry(s_rt, &m_rt->slave_rt_list, m_rt_node) {
		slave = s_rt->slave;

		if (slave->ops->bus_config) {
			ret = slave->ops->bus_config(slave, &bus->params);
			if (ret < 0)
				dev_err(bus->dev, "Notify Slave: %d failed",
								slave->dev_num);
			return ret;
		}
	}

	return ret;
}

/**
 * sdw_program_params() - Program transport and port parameters for Master(s)
 * and Slave(s)
 *
 * @bus: SDW bus instance
 */
static int sdw_program_params(struct sdw_bus *bus)
{
	struct sdw_master_runtime *m_rt = NULL;
	int ret = 0;

	list_for_each_entry(m_rt, &bus->m_rt_list, bus_node) {
		ret = sdw_program_port_params(m_rt);
		if (ret < 0) {
			dev_err(bus->dev,
				"Program transport params failed: %d", ret);
			return ret;
		}

		ret = sdw_notify_config(m_rt);
		if (ret < 0) {
			dev_err(bus->dev, "Notify bus config failed: %d", ret);
			return ret;
		}

		/* Enable port(s) on alternate bank for all active streams */
		if (m_rt->stream->state != SDW_STREAM_ENABLED)
			continue;

		ret = sdw_enable_disable_ports(m_rt, true);
		if (ret < 0) {
			dev_err(bus->dev, "Enable channel failed: %d", ret);
			return ret;
		}
	}

	return ret;
}

static int sdw_bank_switch(struct sdw_bus *bus)
{
	int col_index, row_index;
	struct sdw_msg *wr_msg;
	u8 *wbuf = NULL;
	int ret = 0;
	u16 addr;

	wr_msg = kzalloc(sizeof(*wr_msg), GFP_KERNEL);
	if (!wr_msg)
		return -ENOMEM;

	wbuf = kzalloc(sizeof(*wbuf), GFP_KERNEL);
	if (!wbuf) {
		ret = -ENOMEM;
		goto error_1;
	}

	/* Get row and column index to program register */
	col_index = sdw_find_col_index(bus->params.col);
	row_index = sdw_find_row_index(bus->params.row);
	wbuf[0] = col_index | (row_index << 3);

	if (bus->params.next_bank)
		addr = SDW_SCP_FRAMECTRL_B1;
	else
		addr = SDW_SCP_FRAMECTRL_B0;

	sdw_fill_msg(wr_msg, NULL, addr, 1, SDW_BROADCAST_DEV_NUM,
					SDW_MSG_FLAG_WRITE, wbuf);
	wr_msg->ssp_sync = true;

	ret = sdw_transfer(bus, wr_msg);
	if (ret < 0) {
		dev_err(bus->dev, "Slave frame_ctrl reg write failed");
		goto error;
	}

	kfree(wr_msg);
	kfree(wbuf);
	bus->defer_msg.msg = NULL;
	bus->params.curr_bank = !bus->params.curr_bank;
	bus->params.next_bank = !bus->params.next_bank;

	return 0;

error:
	kfree(wbuf);
error_1:
	kfree(wr_msg);
	return ret;
}

static int do_bank_switch(struct sdw_stream_runtime *stream)
{
	struct sdw_master_runtime *m_rt = stream->m_rt;
	const struct sdw_master_ops *ops;
	struct sdw_bus *bus = m_rt->bus;
	int ret = 0;

	ops = bus->ops;

	/* Pre-bank switch */
	if (ops->pre_bank_switch) {
		ret = ops->pre_bank_switch(bus);
		if (ret < 0) {
			dev_err(bus->dev, "Pre bank switch op failed: %d", ret);
			return ret;
		}
	}

	/* Bank switch */
	ret = sdw_bank_switch(bus);
	if (ret < 0) {
		dev_err(bus->dev, "Bank switch failed: %d", ret);
		return ret;
	}

	/* Post-bank switch */
	if (ops->post_bank_switch) {
		ret = ops->post_bank_switch(bus);
		if (ret < 0) {
			dev_err(bus->dev,
					"Post bank switch op failed: %d", ret);
		}
	}

	return ret;
}

/**
 * sdw_release_stream() - Free the assigned stream runtime
 *
 * @stream: SoundWire stream runtime
 *
 * sdw_release_stream should be called only once per stream
 */
void sdw_release_stream(struct sdw_stream_runtime *stream)
{
	kfree(stream);
}
EXPORT_SYMBOL(sdw_release_stream);

/**
 * sdw_alloc_stream() - Allocate and return stream runtime
 *
 * @stream_name: SoundWire stream name
 *
 * Allocates a SoundWire stream runtime instance.
 * sdw_alloc_stream should be called only once per stream. Typically
 * invoked from ALSA/ASoC machine/platform driver.
 */
struct sdw_stream_runtime *sdw_alloc_stream(char *stream_name)
{
	struct sdw_stream_runtime *stream;

	stream = kzalloc(sizeof(*stream), GFP_KERNEL);
	if (!stream)
		return NULL;

	stream->name = stream_name;
	stream->state = SDW_STREAM_ALLOCATED;

	return stream;
}
EXPORT_SYMBOL(sdw_alloc_stream);

/**
 * sdw_alloc_master_rt() - Allocates and initialize Master runtime handle
 *
 * @bus: SDW bus instance
 * @stream_config: Stream configuration
 * @stream: Stream runtime handle.
 *
 * This function is to be called with bus_lock held.
 */
static struct sdw_master_runtime
*sdw_alloc_master_rt(struct sdw_bus *bus,
			struct sdw_stream_config *stream_config,
			struct sdw_stream_runtime *stream)
{
	struct sdw_master_runtime *m_rt;

	m_rt = stream->m_rt;

	/*
	 * check if Master is already allocated (as a result of Slave adding
	 * it first), if so skip allocation and go to configure
	 */
	if (m_rt)
		goto stream_config;

	m_rt = kzalloc(sizeof(*m_rt), GFP_KERNEL);
	if (!m_rt)
		return NULL;

	/* Initialization of Master runtime handle */
	INIT_LIST_HEAD(&m_rt->port_list);
	INIT_LIST_HEAD(&m_rt->slave_rt_list);
	stream->m_rt = m_rt;

	list_add_tail(&m_rt->bus_node, &bus->m_rt_list);

stream_config:
	m_rt->ch_count = stream_config->ch_count;
	m_rt->bus = bus;
	m_rt->stream = stream;
	m_rt->direction = stream_config->direction;

	return m_rt;
}

/**
 * sdw_alloc_slave_rt() - Allocate and initialize Slave runtime handle.
 *
 * @slave: Slave handle
 * @stream_config: Stream configuration
 * @stream: Stream runtime handle
 *
 * This function is to be called with bus_lock held.
 */
static struct sdw_slave_runtime
*sdw_alloc_slave_rt(struct sdw_slave *slave,
			struct sdw_stream_config *stream_config,
			struct sdw_stream_runtime *stream)
{
	struct sdw_slave_runtime *s_rt = NULL;

	s_rt = kzalloc(sizeof(*s_rt), GFP_KERNEL);
	if (!s_rt)
		return NULL;

	INIT_LIST_HEAD(&s_rt->port_list);
	s_rt->ch_count = stream_config->ch_count;
	s_rt->direction = stream_config->direction;
	s_rt->slave = slave;

	return s_rt;
}

static void sdw_master_port_release(struct sdw_bus *bus,
			struct sdw_master_runtime *m_rt)
{
	struct sdw_port_runtime *p_rt, *_p_rt;

	list_for_each_entry_safe(p_rt, _p_rt,
			&m_rt->port_list, port_node) {
		list_del(&p_rt->port_node);
		kfree(p_rt);
	}
}

static void sdw_slave_port_release(struct sdw_bus *bus,
			struct sdw_slave *slave,
			struct sdw_stream_runtime *stream)
{
	struct sdw_port_runtime *p_rt, *_p_rt;
	struct sdw_master_runtime *m_rt = stream->m_rt;
	struct sdw_slave_runtime *s_rt;

	list_for_each_entry(s_rt, &m_rt->slave_rt_list, m_rt_node) {
		if (s_rt->slave != slave)
			continue;

		list_for_each_entry_safe(p_rt, _p_rt,
				&s_rt->port_list, port_node) {
			list_del(&p_rt->port_node);
			kfree(p_rt);
		}
	}
}

/**
 * sdw_release_slave_stream() - Free Slave(s) runtime handle
 *
 * @slave: Slave handle.
 * @stream: Stream runtime handle.
 *
 * This function is to be called with bus_lock held.
 */
static void sdw_release_slave_stream(struct sdw_slave *slave,
			struct sdw_stream_runtime *stream)
{
	struct sdw_slave_runtime *s_rt, *_s_rt;
	struct sdw_master_runtime *m_rt = stream->m_rt;

	/* Retrieve Slave runtime handle */
	list_for_each_entry_safe(s_rt, _s_rt,
			&m_rt->slave_rt_list, m_rt_node) {

		if (s_rt->slave == slave) {
			list_del(&s_rt->m_rt_node);
			kfree(s_rt);
			return;
		}
	}
}

/**
 * sdw_release_master_stream() - Free Master runtime handle
 *
 * @stream: Stream runtime handle.
 *
 * This function is to be called with bus_lock held
 * It frees the Master runtime handle and associated Slave(s) runtime
 * handle. If this is called first then sdw_release_slave_stream() will have
 * no effect as Slave(s) runtime handle would already be freed up.
 */
static void sdw_release_master_stream(struct sdw_stream_runtime *stream)
{
	struct sdw_master_runtime *m_rt = stream->m_rt;
	struct sdw_slave_runtime *s_rt, *_s_rt;

	list_for_each_entry_safe(s_rt, _s_rt, &m_rt->slave_rt_list, m_rt_node) {
		sdw_slave_port_release(s_rt->slave->bus, s_rt->slave, stream);
		sdw_release_slave_stream(s_rt->slave, stream);
	}

	list_del(&m_rt->bus_node);
}

/**
 * sdw_stream_remove_master() - Remove master from sdw_stream
 *
 * @bus: SDW Bus instance
 * @stream: SoundWire stream
 *
 * This removes and frees port_rt and master_rt from a stream
 */
int sdw_stream_remove_master(struct sdw_bus *bus,
		struct sdw_stream_runtime *stream)
{
	mutex_lock(&bus->bus_lock);

	sdw_release_master_stream(stream);
	sdw_master_port_release(bus, stream->m_rt);
	stream->state = SDW_STREAM_RELEASED;
	kfree(stream->m_rt);
	stream->m_rt = NULL;

	mutex_unlock(&bus->bus_lock);

	return 0;
}
EXPORT_SYMBOL(sdw_stream_remove_master);

/**
 * sdw_stream_remove_slave() - Remove slave from sdw_stream
 *
 * @slave: SDW Slave instance
 * @stream: SoundWire stream
 *
 * This removes and frees port_rt and slave_rt from a stream
 */
int sdw_stream_remove_slave(struct sdw_slave *slave,
		struct sdw_stream_runtime *stream)
{
	mutex_lock(&slave->bus->bus_lock);

	sdw_slave_port_release(slave->bus, slave, stream);
	sdw_release_slave_stream(slave, stream);

	mutex_unlock(&slave->bus->bus_lock);

	return 0;
}
EXPORT_SYMBOL(sdw_stream_remove_slave);

/**
 * sdw_config_stream() - Configure the allocated stream
 *
 * @dev: SDW device
 * @stream: SoundWire stream
 * @stream_config: Stream configuration for audio stream
 * @is_slave: is API called from Slave or Master
 *
 * This function is to be called with bus_lock held.
 */
static int sdw_config_stream(struct device *dev,
		struct sdw_stream_runtime *stream,
		struct sdw_stream_config *stream_config, bool is_slave)
{
	/*
	 * Update the stream rate, channel and bps based on data
	 * source. For more than one data source (multilink),
	 * match the rate, bps, stream type and increment number of channels.
	 *
	 * If rate/bps is zero, it means the values are not set, so skip
	 * comparison and allow the value to be set and stored in stream
	 */
	if (stream->params.rate &&
			stream->params.rate != stream_config->frame_rate) {
		dev_err(dev, "rate not matching, stream:%s", stream->name);
		return -EINVAL;
	}

	if (stream->params.bps &&
			stream->params.bps != stream_config->bps) {
		dev_err(dev, "bps not matching, stream:%s", stream->name);
		return -EINVAL;
	}

	stream->type = stream_config->type;
	stream->params.rate = stream_config->frame_rate;
	stream->params.bps = stream_config->bps;

	/* TODO: Update this check during Device-device support */
	if (is_slave)
		stream->params.ch_count += stream_config->ch_count;

	return 0;
}

static int sdw_is_valid_port_range(struct device *dev,
				struct sdw_port_runtime *p_rt)
{
	if (!SDW_VALID_PORT_RANGE(p_rt->num)) {
		dev_err(dev,
			"SoundWire: Invalid port number :%d", p_rt->num);
		return -EINVAL;
	}

	return 0;
}

static struct sdw_port_runtime *sdw_port_alloc(struct device *dev,
				struct sdw_port_config *port_config,
				int port_index)
{
	struct sdw_port_runtime *p_rt;

	p_rt = kzalloc(sizeof(*p_rt), GFP_KERNEL);
	if (!p_rt)
		return NULL;

	p_rt->ch_mask = port_config[port_index].ch_mask;
	p_rt->num = port_config[port_index].num;

	return p_rt;
}

static int sdw_master_port_config(struct sdw_bus *bus,
			struct sdw_master_runtime *m_rt,
			struct sdw_port_config *port_config,
			unsigned int num_ports)
{
	struct sdw_port_runtime *p_rt;
	int i;

	/* Iterate for number of ports to perform initialization */
	for (i = 0; i < num_ports; i++) {
		p_rt = sdw_port_alloc(bus->dev, port_config, i);
		if (!p_rt)
			return -ENOMEM;

		/*
		 * TODO: Check port capabilities for requested
		 * configuration (audio mode support)
		 */

		list_add_tail(&p_rt->port_node, &m_rt->port_list);
	}

	return 0;
}

static int sdw_slave_port_config(struct sdw_slave *slave,
			struct sdw_slave_runtime *s_rt,
			struct sdw_port_config *port_config,
			unsigned int num_config)
{
	struct sdw_port_runtime *p_rt;
	int i, ret;

	/* Iterate for number of ports to perform initialization */
	for (i = 0; i < num_config; i++) {
		p_rt = sdw_port_alloc(&slave->dev, port_config, i);
		if (!p_rt)
			return -ENOMEM;

		/*
		 * TODO: Check valid port range as defined by DisCo/
		 * slave
		 */
		ret = sdw_is_valid_port_range(&slave->dev, p_rt);
		if (ret < 0) {
			kfree(p_rt);
			return ret;
		}

		/*
		 * TODO: Check port capabilities for requested
		 * configuration (audio mode support)
		 */

		list_add_tail(&p_rt->port_node, &s_rt->port_list);
	}

	return 0;
}

/**
 * sdw_stream_add_master() - Allocate and add master runtime to a stream
 *
 * @bus: SDW Bus instance
 * @stream_config: Stream configuration for audio stream
 * @port_config: Port configuration for audio stream
 * @num_ports: Number of ports
 * @stream: SoundWire stream
 */
int sdw_stream_add_master(struct sdw_bus *bus,
		struct sdw_stream_config *stream_config,
		struct sdw_port_config *port_config,
		unsigned int num_ports,
		struct sdw_stream_runtime *stream)
{
	struct sdw_master_runtime *m_rt = NULL;
	int ret;

	mutex_lock(&bus->bus_lock);

	m_rt = sdw_alloc_master_rt(bus, stream_config, stream);
	if (!m_rt) {
		dev_err(bus->dev,
				"Master runtime config failed for stream:%s",
				stream->name);
		ret = -ENOMEM;
		goto unlock;
	}

	ret = sdw_config_stream(bus->dev, stream, stream_config, false);
	if (ret)
		goto stream_error;

	ret = sdw_master_port_config(bus, m_rt, port_config, num_ports);
	if (ret)
		goto stream_error;

	goto unlock;

stream_error:
	sdw_release_master_stream(stream);
unlock:
	mutex_unlock(&bus->bus_lock);
	return ret;
}
EXPORT_SYMBOL(sdw_stream_add_master);

/**
 * sdw_stream_add_slave() - Allocate and add master/slave runtime to a stream
 *
 * @slave: SDW Slave instance
 * @stream_config: Stream configuration for audio stream
 * @stream: SoundWire stream
 * @port_config: Port configuration for audio stream
 * @num_ports: Number of ports
 *
 * It is expected that Slave is added before adding Master
 * to the Stream.
 *
 */
int sdw_stream_add_slave(struct sdw_slave *slave,
		struct sdw_stream_config *stream_config,
		struct sdw_port_config *port_config,
		unsigned int num_ports,
		struct sdw_stream_runtime *stream)
{
	struct sdw_slave_runtime *s_rt;
	struct sdw_master_runtime *m_rt;
	int ret;

	mutex_lock(&slave->bus->bus_lock);

	/*
	 * If this API is invoked by Slave first then m_rt is not valid.
	 * So, allocate m_rt and add Slave to it.
	 */
	m_rt = sdw_alloc_master_rt(slave->bus, stream_config, stream);
	if (!m_rt) {
		dev_err(&slave->dev,
				"alloc master runtime failed for stream:%s",
				stream->name);
		ret = -ENOMEM;
		goto error;
	}

	s_rt = sdw_alloc_slave_rt(slave, stream_config, stream);
	if (!s_rt) {
		dev_err(&slave->dev,
				"Slave runtime config failed for stream:%s",
				stream->name);
		ret = -ENOMEM;
		goto stream_error;
	}

	ret = sdw_config_stream(&slave->dev, stream, stream_config, true);
	if (ret)
		goto stream_error;

	list_add_tail(&s_rt->m_rt_node, &m_rt->slave_rt_list);

	ret = sdw_slave_port_config(slave, s_rt, port_config, num_ports);
	if (ret)
		goto stream_error;

	/*
	 * Change stream state to CONFIGURED on first Slave add.
	 * Bus is not aware of number of Slave(s) in a stream at this
	 * point so cannot depend on all Slave(s) to be added in order to
	 * change stream state to CONFIGURED.
	 */
	stream->state = SDW_STREAM_CONFIGURED;
	goto error;

stream_error:
	/*
	 * we hit error so cleanup the stream, release all Slave(s) and
	 * Master runtime
	 */
	sdw_release_master_stream(stream);
error:
	mutex_unlock(&slave->bus->bus_lock);
	return ret;
}
EXPORT_SYMBOL(sdw_stream_add_slave);

/**
 * sdw_get_slave_dpn_prop() - Get Slave port capabilities
 *
 * @slave: Slave handle
 * @direction: Data direction.
 * @port_num: Port number
 */
struct sdw_dpn_prop *sdw_get_slave_dpn_prop(struct sdw_slave *slave,
				enum sdw_data_direction direction,
				unsigned int port_num)
{
	struct sdw_dpn_prop *dpn_prop;
	u8 num_ports;
	int i;

	if (direction == SDW_DATA_DIR_TX) {
		num_ports = hweight32(slave->prop.source_ports);
		dpn_prop = slave->prop.src_dpn_prop;
	} else {
		num_ports = hweight32(slave->prop.sink_ports);
		dpn_prop = slave->prop.sink_dpn_prop;
	}

	for (i = 0; i < num_ports; i++) {
		if (dpn_prop[i].num == port_num)
			return &dpn_prop[i];
	}

	return NULL;
}

static int _sdw_prepare_stream(struct sdw_stream_runtime *stream)
{
	struct sdw_master_runtime *m_rt = stream->m_rt;
	struct sdw_bus *bus = m_rt->bus;
	struct sdw_master_prop *prop = NULL;
	struct sdw_bus_params params;
	int ret;

	prop = &bus->prop;
	memcpy(&params, &bus->params, sizeof(params));

	/* TODO: Support Asynchronous mode */
	if ((prop->max_freq % stream->params.rate) != 0) {
		dev_err(bus->dev, "Async mode not supported");
		return -EINVAL;
	}

	/* Increment cumulative bus bandwidth */
	/* TODO: Update this during Device-Device support */
	bus->params.bandwidth += m_rt->stream->params.rate *
		m_rt->ch_count * m_rt->stream->params.bps;

	/* Program params */
	ret = sdw_program_params(bus);
	if (ret < 0) {
		dev_err(bus->dev, "Program params failed: %d", ret);
		goto restore_params;
	}

	ret = do_bank_switch(stream);
	if (ret < 0) {
		dev_err(bus->dev, "Bank switch failed: %d", ret);
		goto restore_params;
	}

	/* Prepare port(s) on the new clock configuration */
	ret = sdw_prep_deprep_ports(m_rt, true);
	if (ret < 0) {
		dev_err(bus->dev, "Prepare port(s) failed ret = %d",
				ret);
		return ret;
	}

	stream->state = SDW_STREAM_PREPARED;

	return ret;

restore_params:
	memcpy(&bus->params, &params, sizeof(params));
	return ret;
}

/**
 * sdw_prepare_stream() - Prepare SoundWire stream
 *
 * @stream: Soundwire stream
 *
 * Documentation/driver-api/soundwire/stream.rst explains this API in detail
 */
int sdw_prepare_stream(struct sdw_stream_runtime *stream)
{
	int ret = 0;

	if (!stream) {
		pr_err("SoundWire: Handle not found for stream");
		return -EINVAL;
	}

	mutex_lock(&stream->m_rt->bus->bus_lock);

	ret = _sdw_prepare_stream(stream);
	if (ret < 0)
		pr_err("Prepare for stream:%s failed: %d", stream->name, ret);

	mutex_unlock(&stream->m_rt->bus->bus_lock);
	return ret;
}
EXPORT_SYMBOL(sdw_prepare_stream);

static int _sdw_enable_stream(struct sdw_stream_runtime *stream)
{
	struct sdw_master_runtime *m_rt = stream->m_rt;
	struct sdw_bus *bus = m_rt->bus;
	int ret;

	/* Program params */
	ret = sdw_program_params(bus);
	if (ret < 0) {
		dev_err(bus->dev, "Program params failed: %d", ret);
		return ret;
	}

	/* Enable port(s) */
	ret = sdw_enable_disable_ports(m_rt, true);
	if (ret < 0) {
		dev_err(bus->dev, "Enable port(s) failed ret: %d", ret);
		return ret;
	}

	ret = do_bank_switch(stream);
	if (ret < 0) {
		dev_err(bus->dev, "Bank switch failed: %d", ret);
		return ret;
	}

	stream->state = SDW_STREAM_ENABLED;
	return 0;
}

/**
 * sdw_enable_stream() - Enable SoundWire stream
 *
 * @stream: Soundwire stream
 *
 * Documentation/driver-api/soundwire/stream.rst explains this API in detail
 */
int sdw_enable_stream(struct sdw_stream_runtime *stream)
{
	int ret = 0;

	if (!stream) {
		pr_err("SoundWire: Handle not found for stream");
		return -EINVAL;
	}

	mutex_lock(&stream->m_rt->bus->bus_lock);

	ret = _sdw_enable_stream(stream);
	if (ret < 0)
		pr_err("Enable for stream:%s failed: %d", stream->name, ret);

	mutex_unlock(&stream->m_rt->bus->bus_lock);
	return ret;
}
EXPORT_SYMBOL(sdw_enable_stream);

static int _sdw_disable_stream(struct sdw_stream_runtime *stream)
{
	struct sdw_master_runtime *m_rt = stream->m_rt;
	struct sdw_bus *bus = m_rt->bus;
	int ret;

	/* Disable port(s) */
	ret = sdw_enable_disable_ports(m_rt, false);
	if (ret < 0) {
		dev_err(bus->dev, "Disable port(s) failed: %d", ret);
		return ret;
	}

	stream->state = SDW_STREAM_DISABLED;

	/* Program params */
	ret = sdw_program_params(bus);
	if (ret < 0) {
		dev_err(bus->dev, "Program params failed: %d", ret);
		return ret;
	}

	return do_bank_switch(stream);
}

/**
 * sdw_disable_stream() - Disable SoundWire stream
 *
 * @stream: Soundwire stream
 *
 * Documentation/driver-api/soundwire/stream.rst explains this API in detail
 */
int sdw_disable_stream(struct sdw_stream_runtime *stream)
{
	int ret = 0;

	if (!stream) {
		pr_err("SoundWire: Handle not found for stream");
		return -EINVAL;
	}

	mutex_lock(&stream->m_rt->bus->bus_lock);

	ret = _sdw_disable_stream(stream);
	if (ret < 0)
		pr_err("Disable for stream:%s failed: %d", stream->name, ret);

	mutex_unlock(&stream->m_rt->bus->bus_lock);
	return ret;
}
EXPORT_SYMBOL(sdw_disable_stream);

static int _sdw_deprepare_stream(struct sdw_stream_runtime *stream)
{
	struct sdw_master_runtime *m_rt = stream->m_rt;
	struct sdw_bus *bus = m_rt->bus;
	int ret = 0;

	/* De-prepare port(s) */
	ret = sdw_prep_deprep_ports(m_rt, false);
	if (ret < 0) {
		dev_err(bus->dev, "De-prepare port(s) failed: %d", ret);
		return ret;
	}

	stream->state = SDW_STREAM_DEPREPARED;

	/* TODO: Update this during Device-Device support */
	bus->params.bandwidth -= m_rt->stream->params.rate *
		m_rt->ch_count * m_rt->stream->params.bps;

	/* Program params */
	ret = sdw_program_params(bus);
	if (ret < 0) {
		dev_err(bus->dev, "Program params failed: %d", ret);
		return ret;
	}

	return do_bank_switch(stream);
}

/**
 * sdw_deprepare_stream() - Deprepare SoundWire stream
 *
 * @stream: Soundwire stream
 *
 * Documentation/driver-api/soundwire/stream.rst explains this API in detail
 */
int sdw_deprepare_stream(struct sdw_stream_runtime *stream)
{
	int ret = 0;

	if (!stream) {
		pr_err("SoundWire: Handle not found for stream");
		return -EINVAL;
	}

	mutex_lock(&stream->m_rt->bus->bus_lock);

	ret = _sdw_deprepare_stream(stream);
	if (ret < 0)
		pr_err("De-prepare for stream:%d failed: %d", ret, ret);

	mutex_unlock(&stream->m_rt->bus->bus_lock);
	return ret;
}
EXPORT_SYMBOL(sdw_deprepare_stream);
