#ifndef SFPB_XML
#define SFPB_XML

/* Autogenerated file, DO NOT EDIT manually!

This file was generated by the rules-ng-ng headergen tool in this git repository:
http://github.com/freedreno/envytools/
git clone https://github.com/freedreno/envytools.git

The rules-ng-ng source files this header was generated from are:
- /home/robclark/src/envytools/rnndb/msm.xml                 (    676 bytes, from 2018-07-03 19:37:13)
- /home/robclark/src/envytools/rnndb/freedreno_copyright.xml (   1572 bytes, from 2018-07-03 19:37:13)
- /home/robclark/src/envytools/rnndb/mdp/mdp4.xml            (  20915 bytes, from 2018-07-03 19:37:13)
- /home/robclark/src/envytools/rnndb/mdp/mdp_common.xml      (   2849 bytes, from 2018-07-03 19:37:13)
- /home/robclark/src/envytools/rnndb/mdp/mdp5.xml            (  37411 bytes, from 2018-07-03 19:37:13)
- /home/robclark/src/envytools/rnndb/dsi/dsi.xml             (  37239 bytes, from 2018-07-03 19:37:13)
- /home/robclark/src/envytools/rnndb/dsi/sfpb.xml            (    602 bytes, from 2018-07-03 19:37:13)
- /home/robclark/src/envytools/rnndb/dsi/mmss_cc.xml         (   1686 bytes, from 2018-07-03 19:37:13)
- /home/robclark/src/envytools/rnndb/hdmi/qfprom.xml         (    600 bytes, from 2018-07-03 19:37:13)
- /home/robclark/src/envytools/rnndb/hdmi/hdmi.xml           (  41799 bytes, from 2018-07-03 19:37:13)
- /home/robclark/src/envytools/rnndb/edp/edp.xml             (  10416 bytes, from 2018-07-03 19:37:13)

Copyright (C) 2013-2018 by the following authors:
- Rob Clark <robdclark@gmail.com> (robclark)
- Ilia Mirkin <imirkin@alum.mit.edu> (imirkin)

Permission is hereby granted, free of charge, to any person obtaining
a copy of this software and associated documentation files (the
"Software"), to deal in the Software without restriction, including
without limitation the rights to use, copy, modify, merge, publish,
distribute, sublicense, and/or sell copies of the Software, and to
permit persons to whom the Software is furnished to do so, subject to
the following conditions:

The above copyright notice and this permission notice (including the
next paragraph) shall be included in all copies or substantial
portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
IN NO EVENT SHALL THE COPYRIGHT OWNER(S) AND/OR ITS SUPPLIERS BE
LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION
OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION
WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/


enum sfpb_ahb_arb_master_port_en {
	SFPB_MASTER_PORT_ENABLE = 3,
	SFPB_MASTER_PORT_DISABLE = 0,
};

#define REG_SFPB_GPREG						0x00000058
#define SFPB_GPREG_MASTER_PORT_EN__MASK				0x00001800
#define SFPB_GPREG_MASTER_PORT_EN__SHIFT			11
static inline uint32_t SFPB_GPREG_MASTER_PORT_EN(enum sfpb_ahb_arb_master_port_en val)
{
	return ((val) << SFPB_GPREG_MASTER_PORT_EN__SHIFT) & SFPB_GPREG_MASTER_PORT_EN__MASK;
}


#endif /* SFPB_XML */
