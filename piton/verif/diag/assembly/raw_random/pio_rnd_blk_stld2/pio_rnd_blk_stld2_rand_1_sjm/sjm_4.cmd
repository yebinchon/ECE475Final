# Modified by Princeton University on June 9th, 2015
# ========== Copyright Header Begin ==========================================
# 
# OpenSPARC T1 Processor File: sjm_4.cmd
# Copyright (c) 2006 Sun Microsystems, Inc.  All Rights Reserved.
# DO NOT ALTER OR REMOVE COPYRIGHT NOTICES.
# 
# The above named program is free software; you can redistribute it and/or
# modify it under the terms of the GNU General Public
# License version 2 as published by the Free Software Foundation.
# 
# The above named program is distributed in the hope that it will be 
# useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
# General Public License for more details.
# 
# You should have received a copy of the GNU General Public
# License along with this work; if not, write to the Free Software
# Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301, USA.
# 
# ========== Copyright Header End ============================================
CONFIG id=28 iosyncadr=0x7CF00BEEF00
TIMEOUT 10000000
IOSYNC
#==================================================
#==================================================


LABEL_0:

WRITEIO  0x0000060d5ff98740 8 0x290334ca 0x2083497e 

WRITEBLK  0x00000016e6cb2340 +
        0xa332e285 0xa38c8a19 0x0521adcf 0x93e85e50 +
        0x90d86baa 0xe50cf50d 0xecc13454 0x55d9e890 +
        0xda772cd1 0x9ba76d39 0xaa8ba0d6 0xfe4a88da +
        0x621f364f 0xea2d8bc2 0x6246f3e2 0xbb454367 

WRITEMSK  0x00000016e6cb2340 0xf00ffff0000fff0f +
        0x74055348 0x00000000 0x00000000 0xb1ba880e +
        0xb2551b7d 0x273c913f 0x065ff07d 0x00000000 +
        0x00000000 0x00000000 0x00000000 0x8c6e0748 +
        0xa3b847e9 0xc34599a0 0x00000000 0xdf67b192 

WRITEBLK  0x000000040bae4140 +
        0x91bd4eb9 0xa21c4440 0xfc5c0bff 0xf209f31d +
        0x40a4e7f5 0x2c5a61e3 0x0bedb9de 0x303d0560 +
        0x7f54965e 0x561a17f1 0xc5709267 0x04c1ebd8 +
        0x3255ae7c 0xa711388a 0xb02a0ea3 0x6f914252 

READIO  0x0000060d5ff98740 8 0x290334ca 0x2083497e 
WRITEMSKIO  0x00000611a9d0fa00 0x0f00  0x00000000 0xd75c7609 0x00000000 0x00000000 

READMSKIO   0x00000611a9d0fa00 0x0f00  0x00000000 0xd75c7609 0x00000000 0x00000000 

WRITEMSKIO  0x0000060e1cbc79c0 0xfff0  0x37aa38bb 0xc02651a6 0x886e2ec9 0x00000000 

WRITEBLKIO  0x0000060c71fa3180 +
        0x48f8e825 0x0a79a768 0xda846da5 0x4c324ec0 +
        0xdd955231 0x3448c9ca 0xb2b69869 0xa68a4bbb +
        0xb1e18fdf 0xdd839123 0x3911b790 0xc759ccd7 +
        0x96ecd804 0xe1c73ab5 0x928a3757 0x03c16593 

WRITEMSKIO  0x0000060b27abcfc0 0x0f0f  0x00000000 0x2204a0fb 0x00000000 0x24bbc3a3 

READBLK  0x00000016e6cb2340 +
        0x74055348 0xa38c8a19 0x0521adcf 0xb1ba880e +
        0xb2551b7d 0x273c913f 0x065ff07d 0x55d9e890 +
        0xda772cd1 0x9ba76d39 0xaa8ba0d6 0x8c6e0748 +
        0xa3b847e9 0xc34599a0 0x6246f3e2 0xdf67b192 

WRITEIO  0x0000061e54ff06c0 4 0x13f4ba8c 

WRITEMSK  0x000000040bae4140 0x00f0ff00f00ff0f0 +
        0x00000000 0x00000000 0xfd6e7779 0x00000000 +
        0x02c7b713 0x1dabb7af 0x00000000 0x00000000 +
        0x257383de 0x00000000 0x00000000 0xc5adab1c +
        0x0597c7b4 0x00000000 0x822a5361 0x00000000 

READIO  0x0000061e54ff06c0 4 0x13f4ba8c 
WRITEMSKIO  0x000006030c4de680 0xf000  0x12ef18f4 0x00000000 0x00000000 0x00000000 

WRITEMSK  0x000000040bae4140 0x00fff0f00ff0fff0 +
        0x00000000 0x00000000 0x3ef51762 0x2c1a2f1b +
        0x00e3908b 0x00000000 0x0cf5d7d7 0x00000000 +
        0x00000000 0x59fb0f33 0x88c5b0f8 0x00000000 +
        0xfb6cc512 0xd63003b4 0x74e79a3d 0x00000000 

READBLKIO  0x0000060c71fa3180 +
        0x48f8e825 0x0a79a768 0xda846da5 0x4c324ec0 +
        0xdd955231 0x3448c9ca 0xb2b69869 0xa68a4bbb +
        0xb1e18fdf 0xdd839123 0x3911b790 0xc759ccd7 +
        0x96ecd804 0xe1c73ab5 0x928a3757 0x03c16593 

WRITEBLKIO  0x0000060b32931d80 +
        0xabb1655d 0xbccfedd9 0xa2ead882 0xe0628d2e +
        0x354900ee 0xb6fa0002 0x9040c151 0x3a40a308 +
        0x2ee2fee1 0xe9118040 0x16ea2386 0xeac15392 +
        0x98031533 0x843eaa22 0xf3198286 0x164d5cba 

WRITEMSKIO  0x0000061300242340 0xf000  0x369b04c9 0x00000000 0x00000000 0x00000000 

WRITEIO  0x000006043ef0cac0 4 0x4b82e561 

WRITEMSK  0x000000040bae4140 0x0000f0f00fff00ff +
        0x00000000 0x00000000 0x00000000 0x00000000 +
        0x51fce4de 0x00000000 0x1fee3850 0x00000000 +
        0x00000000 0x21c8c65e 0xd3be8905 0xc6bfc7c3 +
        0x00000000 0x00000000 0x0f5ea763 0xe148335e 

READBLK  0x000000040bae4140 +
        0x91bd4eb9 0xa21c4440 0x3ef51762 0x2c1a2f1b +
        0x51fce4de 0x1dabb7af 0x1fee3850 0x303d0560 +
        0x257383de 0x21c8c65e 0xd3be8905 0xc6bfc7c3 +
        0xfb6cc512 0xd63003b4 0x0f5ea763 0xe148335e 

WRITEMSKIO  0x0000060a175a4940 0x0f0f  0x00000000 0xbdfad9b1 0x00000000 0x08d558e1 

WRITEBLKIO  0x0000060e9978dd40 +
        0x91d67af3 0x74077eee 0x1898edf9 0xae40c920 +
        0x6d5552ad 0x51381e28 0x79cca9bd 0x9875db28 +
        0x6c0efc63 0x0dc008a2 0xca345268 0x453fb34f +
        0xcf0ddf26 0x897fa251 0xb64cde58 0x758cc3b5 

WRITEBLKIO  0x000006027c3a42c0 +
        0x3c6b99f8 0xcc5d206c 0x376baaf3 0x78a37555 +
        0x12994a93 0x0b77b87d 0x4ad66e21 0x8e5523b1 +
        0x06bccab2 0xaacf9dc4 0xbf17a428 0x748c164b +
        0x8a9d3e1e 0x4ee1a040 0x3d7bbd79 0x6e9a31ae 

WRITEMSKIO  0x0000061dac33a140 0x0000  0x00000000 0x00000000 0x00000000 0x00000000 

WRITEMSKIO  0x0000060216fc0500 0xfff0  0x911a13e7 0x8a21d9d4 0xbc043196 0x00000000 

WRITEIO  0x0000061088716a80 16 0x5a73b780 0x44f43db3 0x4b9b3e8b 0x3b6c8512 

WRITEBLK  0x00000004dd0d7880 +
        0x469f3f76 0x31472e92 0xe2bc70c1 0x62893a0e +
        0x696967ef 0x195f3d75 0xf70f1709 0x98f85e49 +
        0x44806904 0x5b17fd21 0xc4c0a520 0x32e9e461 +
        0x115e1744 0xd34a7130 0x26356453 0xe5c8ae93 

READIO  0x000006043ef0cac0 4 0x4b82e561 
READBLKIO  0x0000060b32931d80 +
        0xabb1655d 0xbccfedd9 0xa2ead882 0xe0628d2e +
        0x354900ee 0xb6fa0002 0x9040c151 0x3a40a308 +
        0x2ee2fee1 0xe9118040 0x16ea2386 0xeac15392 +
        0x98031533 0x843eaa22 0xf3198286 0x164d5cba 

READBLK  0x00000004dd0d7880 +
        0x469f3f76 0x31472e92 0xe2bc70c1 0x62893a0e +
        0x696967ef 0x195f3d75 0xf70f1709 0x98f85e49 +
        0x44806904 0x5b17fd21 0xc4c0a520 0x32e9e461 +
        0x115e1744 0xd34a7130 0x26356453 0xe5c8ae93 

WRITEBLK  0x0000001e06970200 +
        0xace2dba7 0xab722cc3 0x700b7eb0 0x3cf78bcc +
        0x44cb4b95 0xf0ad9d9e 0x7ac25ed5 0x971b39b5 +
        0xfed378f3 0xf87698f5 0x56dc846d 0x858f7bdc +
        0x87f538f6 0x3afcd4ec 0x7c289e9b 0x411f917f 

READIO  0x0000061088716a80 16 0x5a73b780 0x44f43db3 0x4b9b3e8b 0x3b6c8512 
READMSKIO   0x0000060e1cbc79c0 0xfff0  0x37aa38bb 0xc02651a6 0x886e2ec9 0x00000000 

WRITEMSK  0x0000001e06970200 0xf00ff00f0f0f0f00 +
        0x360a85e3 0x00000000 0x00000000 0x89b53057 +
        0xfdd15895 0x00000000 0x00000000 0x150499d4 +
        0x00000000 0x945a947c 0x00000000 0x5f5abc03 +
        0x00000000 0x9c9a52d5 0x00000000 0x00000000 

READBLK  0x0000001e06970200 +
        0x360a85e3 0xab722cc3 0x700b7eb0 0x89b53057 +
        0xfdd15895 0xf0ad9d9e 0x7ac25ed5 0x150499d4 +
        0xfed378f3 0x945a947c 0x56dc846d 0x5f5abc03 +
        0x87f538f6 0x9c9a52d5 0x7c289e9b 0x411f917f 

READBLKIO  0x0000060e9978dd40 +
        0x91d67af3 0x74077eee 0x1898edf9 0xae40c920 +
        0x6d5552ad 0x51381e28 0x79cca9bd 0x9875db28 +
        0x6c0efc63 0x0dc008a2 0xca345268 0x453fb34f +
        0xcf0ddf26 0x897fa251 0xb64cde58 0x758cc3b5 

WRITEBLK  0x00000017f283fa40 +
        0xa421f00f 0xe8409632 0x9b8b5e11 0xdd51e644 +
        0xe3da1c9e 0xcb3e4ce5 0x06d5e8a6 0x93ca5b49 +
        0x2bcc1b19 0x12242991 0xec83deb5 0x7eb6c287 +
        0xba6e72ab 0x6697df0d 0x744d4d3e 0xfcf49e26 

READBLKIO  0x000006027c3a42c0 +
        0x3c6b99f8 0xcc5d206c 0x376baaf3 0x78a37555 +
        0x12994a93 0x0b77b87d 0x4ad66e21 0x8e5523b1 +
        0x06bccab2 0xaacf9dc4 0xbf17a428 0x748c164b +
        0x8a9d3e1e 0x4ee1a040 0x3d7bbd79 0x6e9a31ae 

WRITEBLKIO  0x0000061de5d6c580 +
        0x3eadbbc1 0xe96eb865 0x6a36511d 0xbb3c7016 +
        0x514dff92 0xcc8ce708 0xcd0a1422 0x72dbc4d9 +
        0x2e827218 0x22e26aa0 0xd003eac7 0x52b6cb51 +
        0x80c28285 0xf21ee4c1 0x0e8d815c 0xbe6247a9 

WRITEIO  0x00000610f9371b40 8 0x6f79e1de 0x8cdf4a54 

WRITEMSKIO  0x00000601fb0a9540 0xff0f  0xfc378117 0xc6657f12 0x00000000 0x5ec12dc1 

READBLK  0x00000017f283fa40 +
        0xa421f00f 0xe8409632 0x9b8b5e11 0xdd51e644 +
        0xe3da1c9e 0xcb3e4ce5 0x06d5e8a6 0x93ca5b49 +
        0x2bcc1b19 0x12242991 0xec83deb5 0x7eb6c287 +
        0xba6e72ab 0x6697df0d 0x744d4d3e 0xfcf49e26 

WRITEBLKIO  0x00000601e5700280 +
        0xe8240c4a 0x0639f487 0xc68c4b17 0xcd8fe56d +
        0xe9ae11a6 0xa8cdedfc 0x316eb96f 0x822a0b44 +
        0xe59d4ee9 0x0ece0703 0xbe92502f 0x13822d22 +
        0xf3f27f91 0xbb2f47c3 0x9f6c6e00 0x84888604 

READIO  0x00000610f9371b40 8 0x6f79e1de 0x8cdf4a54 
READBLKIO  0x0000061de5d6c580 +
        0x3eadbbc1 0xe96eb865 0x6a36511d 0xbb3c7016 +
        0x514dff92 0xcc8ce708 0xcd0a1422 0x72dbc4d9 +
        0x2e827218 0x22e26aa0 0xd003eac7 0x52b6cb51 +
        0x80c28285 0xf21ee4c1 0x0e8d815c 0xbe6247a9 

WRITEMSKIO  0x000006098baf8940 0xffff  0x90f3cfc8 0xa3491318 0x42b1bd6b 0x48fcb21d 

WRITEBLKIO  0x00000610d037bd80 +
        0x43599bb4 0xa952773d 0xd29fc16d 0x0e40dded +
        0xff57bd2b 0xc87aa4df 0xc844e4f3 0x4d4954cb +
        0x0f2e04f8 0xff5456f8 0x486fea64 0x6768a067 +
        0x2d97ff75 0xdbc733cb 0x5cbf7979 0xf4772c30 

WRITEBLKIO  0x00000606b3a03240 +
        0x4b164e4a 0xfef78220 0x574ee7cd 0x55e29fad +
        0x59d0c8a4 0xd3be3ee3 0x7553f7b3 0x942a6c23 +
        0x5cd27d98 0xeccabc34 0xb6929e71 0x2d0427da +
        0xae9c6210 0xfb643553 0xfe396c37 0x45895698 

READBLKIO  0x00000601e5700280 +
        0xe8240c4a 0x0639f487 0xc68c4b17 0xcd8fe56d +
        0xe9ae11a6 0xa8cdedfc 0x316eb96f 0x822a0b44 +
        0xe59d4ee9 0x0ece0703 0xbe92502f 0x13822d22 +
        0xf3f27f91 0xbb2f47c3 0x9f6c6e00 0x84888604 

WRITEBLK  0x00000017a3c91700 +
        0xeedf89ca 0x2a162203 0x4fd8c04d 0xa5f3d198 +
        0x7952ea73 0xa6d94f0e 0xf36fe078 0x053bb066 +
        0xdad803b9 0x581f0ff7 0x2dc4094d 0x7b88eec3 +
        0x28c13828 0xe1d9cfea 0x38afe8e1 0xea965fc8 

WRITEBLKIO  0x0000060ca35e7240 +
        0x0844d7fa 0x96ae1547 0x8e1bec2c 0xa5c9c8f1 +
        0x74f10d52 0xf323635d 0x74696ccc 0x454c0c96 +
        0xa6a8edde 0xac943eca 0xa65facff 0x70c71c90 +
        0xfbc6587f 0xa8611d7c 0x35283aa5 0xa2f0ddb5 

WRITEBLKIO  0x0000060612fa5300 +
        0x398ce816 0x7a869d63 0x84f1d2a9 0x5c601e7c +
        0x92df7a05 0x9204c002 0x1f6fb974 0xb97e746e +
        0x67e41e10 0x6ca6ce00 0x3afc2334 0x4e8417da +
        0x5bd66fbb 0x18bcca4d 0xdf2ede46 0x28dcf9f6 

WRITEBLK  0x00000017e0e51500 +
        0x0c06b7ef 0xb6d01933 0x9ed6fdb8 0xd87299e8 +
        0xb631d33b 0x2a2b7add 0x096dabb5 0x5152f846 +
        0xbfeb03cc 0x686caf44 0x77d4851f 0xea023192 +
        0x275c842a 0x0ea43e4c 0xaf089a53 0xaeb18b51 

WRITEMSK  0x00000017a3c91700 0x0ff0ff0ffffff0ff +
        0x00000000 0x0813ca29 0x81dcdf08 0x00000000 +
        0x302eebef 0x792628d3 0x00000000 0x3a416534 +
        0x1978e16c 0x04225b49 0x1b14189b 0xa842cf4d +
        0x7bd76d95 0x00000000 0x68f09736 0x0c40cef0 

READBLK  0x00000017a3c91700 +
        0xeedf89ca 0x0813ca29 0x81dcdf08 0xa5f3d198 +
        0x302eebef 0x792628d3 0xf36fe078 0x3a416534 +
        0x1978e16c 0x04225b49 0x1b14189b 0xa842cf4d +
        0x7bd76d95 0xe1d9cfea 0x68f09736 0x0c40cef0 


BA LABEL_0