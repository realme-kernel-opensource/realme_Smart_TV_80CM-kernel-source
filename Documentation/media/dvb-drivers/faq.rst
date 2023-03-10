FAQ
===

.. note::

   This documentation is outdated. Please check at the DVB wiki
   at https://linuxtv.org/wiki for more updated info.

Some very frequently asked questions about linuxtv-dvb

1. The signal seems to die a few seconds after tuning.

	It's not a bug, it's a feature. Because the frontends have
	significant power requirements (and hence get very hot), they
	are powered down if they are unused (i.e. if the frontend device
	is closed). The dvb-core.o module parameter "dvb_shutdown_timeout"
	allow you to change the timeout (default 5 seconds). Setting the
	timeout to 0 disables the timeout feature.

2. How can I watch TV?

	The driver distribution includes some simple utilities which
	are mainly intended for testing and to demonstrate how the
	DVB API works.

	Depending on whether you have a DVB-S, DVB-C or DVB-T card, use
	apps/szap/szap, czap or tzap. You must supply a channel list
	in ~/.[sct]zap/channels.conf. If you are lucky you can just copy
	one of the supplied channel lists, or you can create a new one
	by running apps/scan/scan. If you run scan on an unknown network
	you might have to supply some start data in apps/scan/initial.h.

	If you have a card with a built-in hardware MPEG-decoder the
	drivers create a video4linux device (/dev/v4l/video0) which
	you can use to watch TV with any v4l application. xawtv is known
	to work. Note that you cannot change channels with xawtv, you
	have to zap using [sct]zap. If you want a nice application for
	TV watching and record/playback, have a look at VDR.

	If your card does not have a hardware MPEG decoder you need
	a software MPEG decoder. Mplayer or xine are known to work.
	Newsflash: MythTV also has DVB support now.
	Note: Only very recent versions of Mplayer and xine can decode.
	MPEG2 transport streams (TS) directly. Then, run
	'[sct]zap channelname -r' in one xterm, and keep it running,
	and start 'mplayer - < /dev/dvb/adapter0/dvr0' or
	'xine stdin://mpeg2 < /dev/dvb/adapter0/dvr0' in a second xterm.
	That's all far from perfect, but it seems no one has written
	a nice DVB application which includes a builtin software MPEG
	decoder yet.

	Newsflash: Newest xine directly supports DVB. Just copy your
	channels.conf to ~/.xine and start 'xine dvb://', or select
	the DVB button in the xine GUI. Channel switching works using the
	numpad pgup/pgdown (NP9 / NP3) keys to scroll through the channel osd
	menu and pressing numpad-enter to switch to the selected channel.

	Note: Older versions of xine and mplayer understand MPEG program
	streams (PS) only, and can be used in conjunction with the
	ts2ps tool from the Metzler Brother's dvb-mpegtools package.

3. Which other DVB applications exist?

	http://www.cadsoft.de/people/kls/vdr/
		Klaus Schmidinger's Video Disk Recorder

	http://www.metzlerbros.org/dvb/
		Metzler Bros. DVB development; alternate drivers and
		DVB utilities, include dvb-mpegtools and tuxzap.

	http://sourceforge.net/projects/dvbtools/
		Dave Chapman's dvbtools package, including
		dvbstream and dvbtune

	http://www.linuxdvb.tv/
		Henning Holtschneider's site with many interesting
		links and docs

	http://www.dbox2.info/
		LinuxDVB on the dBox2

	http://www.tuxbox.org/ and http://cvs.tuxbox.org/
		the TuxBox CVS many interesting DVB applications and the dBox2
		DVB source

	https://linuxtv.org/downloads
		DVB Swiss Army Knife library and utilities

	http://www.nenie.org/misc/mpsys/
		MPSYS: a MPEG2 system library and tools

	http://mplayerhq.hu/
		mplayer

	http://xine.sourceforge.net/ and http://xinehq.de/
		xine

	http://www.mythtv.org/
		MythTV - analog TV PVR, but now with DVB support, too
		(with software MPEG decode)

	http://dvbsnoop.sourceforge.net/
		DVB sniffer program to monitor, analyze, debug, dump
		or view dvb/mpeg/dsm-cc/mhp stream information (TS,
		PES, SECTION)

4. Can't get a signal tuned correctly

	If you are using a Technotrend/Hauppauge DVB-C card *without* analog
	module, you might have to use module parameter adac=-1 (dvb-ttpci.o).

5. The dvb_net device doesn't give me any packets at all

	Run tcpdump on the dvb0_0 interface. This sets the interface
	into promiscuous mode so it accepts any packets from the PID
	you have configured with the dvbnet utility. Check if there
	are any packets with the IP addr and MAC addr you have
	configured with ifconfig.

	If tcpdump doesn't give you any output, check the statistics
	which ifconfig outputs. (Note: If the MAC address is wrong,
	dvb_net won't get any input; thus you have to run tcpdump
	before checking the statistics.) If there are no packets at
	all then maybe the PID is wrong. If there are error packets,
	then either the PID is wrong or the stream does not conform to
	the MPE standard (EN 301 192, http://www.etsi.org/). You can
	use e.g. dvbsnoop for debugging.

6. The dvb_net device doesn't give me any multicast packets

	Check your routes if they include the multicast address range.
	Additionally make sure that "source validation by reversed path
	lookup" is disabled:

.. code-block:: none

	  $ "echo 0 > /proc/sys/net/ipv4/conf/dvb0/rp_filter"

7. What the hell are all those modules that need to be loaded?

	For a dvb-ttpci av7110 based full-featured card the following
	modules are loaded:

	- videodev: Video4Linux core module. This is the base module that
	  gives you access to the "analog" tv picture of the av7110 mpeg2
	  decoder.

	- v4l2-common: common functions for Video4Linux-2 drivers

	- v4l1-compat: backward compatibility layer for Video4Linux-1 legacy
	  applications

	- dvb-core: DVB core module. This provides you with the
	  /dev/dvb/adapter entries

	- saa7146: SAA7146 core driver. This is need to access any SAA7146
	  based card in your system.

	- saa7146_vv: SAA7146 video and vbi functions. These are only needed
	  for full-featured cards.

	- videobuf-dma-sg: capture helper module for the saa7146_vv driver. This
	  one is responsible to handle capture buffers.

	- dvb-ttpci: The main driver for AV7110 based, full-featured
	  DVB-S/C/T cards

