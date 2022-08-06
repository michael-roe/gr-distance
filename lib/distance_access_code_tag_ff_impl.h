/* -*- c++ -*- */
/*
 * Copyright 2022 Michael Roe.
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#ifndef INCLUDED_DISTANCE_DISTANCE_ACCESS_CODE_TAG_FF_IMPL_H
#define INCLUDED_DISTANCE_DISTANCE_ACCESS_CODE_TAG_FF_IMPL_H

#include <gnuradio/distance/distance_access_code_tag_ff.h>

namespace gr {
namespace distance {

class distance_access_code_tag_ff_impl : public distance_access_code_tag_ff {
private:
  int d_symbols;
  int d_bps;
  float d_distance;
  float d_code[64];

public:
  distance_access_code_tag_ff_impl(int symbols, int bps, float distance,
                                   unsigned long long code);
  ~distance_access_code_tag_ff_impl();

  // Where all the action really happens
  int work(int noutput_items, gr_vector_const_void_star &input_items,
           gr_vector_void_star &output_items);
};

} // namespace distance
} // namespace gr

#endif /* INCLUDED_DISTANCE_DISTANCE_ACCESS_CODE_TAG_FF_IMPL_H */
