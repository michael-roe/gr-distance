/* -*- c++ -*- */
/*
 * Copyright 2022 Michael Roe.
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#include "distance_access_code_tag_ff_impl.h"
#include <gnuradio/io_signature.h>

namespace gr {
namespace distance {

distance_access_code_tag_ff::sptr
distance_access_code_tag_ff::make(int symbols, int bps, float distance,
                                  unsigned long long code) {
  return gnuradio::make_block_sptr<distance_access_code_tag_ff_impl>(
      symbols, bps, distance, code);
}

/*
 * The private constructor
 */
distance_access_code_tag_ff_impl::distance_access_code_tag_ff_impl(
    int symbols, int bps, float distance, unsigned long long code)
    : gr::sync_block(
          "distance_access_code_tag_ff",
          gr::io_signature::make(1, 1, sizeof(float)),
          gr::io_signature::make(1, 1, sizeof(float)))
{
  set_history(symbols + 1);
  d_symbols = symbols;
  d_bps = bps;
  d_distance = distance;
}

/*
 * Our virtual destructor.
 */
distance_access_code_tag_ff_impl::~distance_access_code_tag_ff_impl() {}

int distance_access_code_tag_ff_impl::work(
    int noutput_items, gr_vector_const_void_star &input_items,
    gr_vector_void_star &output_items) {
  float *in = (float *) input_items[0];
  float *out = (float *) output_items[0];
  int i;

  for (i=0; i<noutput_items; i++)
  {
    out[i] = in[i];
  }

  // Tell runtime system how many output items we produced.
  return noutput_items;
}

} /* namespace distance */
} /* namespace gr */
