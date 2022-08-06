#!/usr/bin/env python
# -*- coding: utf-8 -*-
#
# Copyright 2022 Michael Roe.
#
# SPDX-License-Identifier: GPL-3.0-or-later
#

from gnuradio import gr, gr_unittest
# from gnuradio import blocks
try:
  from gnuradio.distance import distance_access_code_tag_ff
except ImportError:
    import os
    import sys
    dirname, filename = os.path.split(os.path.abspath(__file__))
    sys.path.append(os.path.join(dirname, "bindings"))
    from gnuradio.distance import distance_access_code_tag_ff

class qa_distance_access_code_tag_ff(gr_unittest.TestCase):

    def setUp(self):
        self.tb = gr.top_block()

    def tearDown(self):
        self.tb = None

    def test_instance(self):
        instance = distance_access_code_tag_ff(20, 2, 1.0, 0xffffffff)

    def test_001_descriptive_test_name(self):
        # set up fg
        self.tb.run()
        # check data


if __name__ == '__main__':
    gr_unittest.run(qa_distance_access_code_tag_ff)
