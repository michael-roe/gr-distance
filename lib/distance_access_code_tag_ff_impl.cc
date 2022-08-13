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
int i;
unsigned int mask;
float bias;

  if (symbols < 1)
  {
    throw std::out_of_range("Less than 1 symbols");
  }

  if (symbols > 64)
  {
    throw std::out_of_range("More than 64 symbols");
  }

  if (bps < 1)
  {
    throw std::out_of_range("Less than 1 bit per symbol");
  }

  if (bps > 2)
  {
    throw std::out_of_range("More than 2 bits per symbol");
  }

  set_history(symbols + 1);
  d_symbols = symbols;
  d_bps = bps;
  d_distance = distance;
  d_offset = 0;
  d_key = pmt::string_to_symbol("distance");

  mask = (1 << bps) - 1;
  bias = -(float)mask;

  for (i=symbols-1; i>=0; i--)
  {
    d_code[i] = bias + 2.0*(code & mask);
    code = code >> bps;
    printf("d_code[i] = %f\n", d_code[i]);
  }
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
  float distance2;
  float delta;
  int i;
  int j;

  for (i=0; i<noutput_items; i++)
  {
    out[i] = in[i];
  }

  for (i=0; i<noutput_items; i++)
  {
    distance2 = 0.0;
    for (j=0; j<d_symbols; j++)
    {
      delta = d_code[j] - in[i + j];
      distance2 += delta*delta;
    }
    if (distance2 <= d_distance*d_distance)
    {
      add_item_tag(0, d_offset + i + d_symbols, d_key, pmt::from_float(sqrtf(distance2)));
    }
  }

  d_offset += noutput_items;
  // Tell runtime system how many output items we produced.
  return noutput_items;
}

} /* namespace distance */
} /* namespace gr */
