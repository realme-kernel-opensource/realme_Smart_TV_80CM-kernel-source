How to get the bt8xx cards working
==================================

Authors: Richard Walker,
	 Jamie Honan,
	 Michael Hunold,
	 Manu Abraham,
	 Uwe Bugla,
	 Michael Krufky

.. note::

   This documentation is outdated. Please check at the DVB wiki
   at https://linuxtv.org/wiki for more updated info.

General information
-------------------

This class of cards has a bt878a as the PCI interface, and require the bttv driver
for accessing the i2c bus and the gpio pins of the bt8xx chipset.
Please see Documentation/media/dvb-drivers/cards.rst => o Cards based on the Conexant Bt8xx PCI bridge:

Compiling kernel please enable:

#) ``Device drivers`` => ``Multimedia devices`` => ``Video For Linux`` => ``Enable Video for Linux API 1 (DEPRECATED)``
#) ``Device drivers`` => ``Multimedia devices`` => ``Video For Linux`` => ``Video Capture Adapters`` => ``BT848 Video For Linux``
#) ``Device drivers`` => ``Multimedia devices`` => ``Digital Video Broadcasting Devices`` => ``DVB for Linux`` ``DVB Core Support`` ``Bt8xx based PCI Cards``

  Please use the following options with care as deselection of drivers which are in fact necessary may result in DVB devices that cannot be tuned due to lack of driver support:
  You can save RAM by deselecting every frontend module that your DVB card does not need.

  First please remove the static dependency of DVB card drivers on all frontend modules for all possible card variants by enabling:

#) ``Device drivers`` => ``Multimedia devices`` => ``Digital Video Broadcasting Devices`` => ``DVB for Linux`` ``DVB Core Support`` ``Load and attach frontend modules as needed``

  If you know the frontend driver that your card needs please enable:

#) ``Device drivers`` => ``Multimedia devices`` => ``Digital Video Broadcasting Devices`` => ``DVB for Linux`` ``DVB Core Support`` ``Customise DVB Frontends`` => ``Customise the frontend modules to build``

 Then please select your card-specific frontend module.

Loading Modules
---------------

Regular case: If the bttv driver detects a bt8xx-based DVB card, all frontend and backend modules will be loaded automatically.
Exceptions are:
- Old TwinHan DST cards or clones with or without CA slot and not containing an Eeprom.
People running udev please see Documentation/media/dvb-drivers/udev.rst.

In the following cases overriding the PCI type detection for dvb-bt8xx might be necessary:

Running TwinHan and Clones
~~~~~~~~~~~~~~~~~~~~~~~~~~

.. code-block:: none

	$ modprobe bttv card=113
	$ modprobe dst

Useful parameters for verbosity level and debugging the dst module:

.. code-block:: none

	verbose=0:		messages are disabled
		1:		only error messages are displayed
		2:		notifications are displayed
		3:		other useful messages are displayed
		4:		debug setting
	dst_addons=0:		card is a free to air (FTA) card only
		0x20:	card has a conditional access slot for scrambled channels

The autodetected values are determined by the cards' "response string".
In your logs see f. ex.: dst_get_device_id: Recognize [DSTMCI].
For bug reports please send in a complete log with verbose=4 activated.
Please also see Documentation/media/dvb-drivers/ci.rst.

Running multiple cards
~~~~~~~~~~~~~~~~~~~~~~

Examples of card ID's:

.. code-block:: none

	Pinnacle PCTV Sat:		 94
	Nebula Electronics Digi TV:	104
	pcHDTV HD-2000 TV:		112
	Twinhan DST and clones:		113
	Avermedia AverTV DVB-T 771:	123
	Avermedia AverTV DVB-T 761:	124
	DViCO FusionHDTV DVB-T Lite:	128
	DViCO FusionHDTV 5 Lite:	135

.. note::

   The order of the card ID should be uprising:

   Example:

   .. code-block:: none

	$ modprobe bttv card=113 card=135

For a full list of card ID's please see Documentation/media/v4l-drivers/bttv-cardlist.rst.
In case of further problems please subscribe and send questions to the mailing list: linux-dvb@linuxtv.org.

Probing the cards with broken PCI subsystem ID
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

There are some TwinHan cards that the EEPROM has become corrupted for some
reason. The cards do not have correct PCI subsystem ID. But we can force
probing the cards with broken PCI subsystem ID

.. code-block:: none

	$ echo 109e 0878 $subvendor $subdevice > \
		/sys/bus/pci/drivers/bt878/new_id

.. code-block:: none

	109e: PCI_VENDOR_ID_BROOKTREE
	0878: PCI_DEVICE_ID_BROOKTREE_878

