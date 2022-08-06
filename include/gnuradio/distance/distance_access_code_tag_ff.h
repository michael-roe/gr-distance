/* -*- c++ -*- */
/*
 * Copyright 2022 Michael Roe.
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#ifndef INCLUDED_DISTANCE_DISTANCE_ACCESS_CODE_TAG_FF_H
#define INCLUDED_DISTANCE_DISTANCE_ACCESS_CODE_TAG_FF_H

#include <gnuradio/distance/api.h>
#include <gnuradio/sync_block.h>

namespace gr {
namespace distance {

/*!
 * \brief <+description of block+>
 * \ingroup distance
 *
 */
class DISTANCE_API distance_access_code_tag_ff : virtual public gr::sync_block {
public:
  typedef std::shared_ptr<distance_access_code_tag_ff> sptr;

  /*!
   * \brief Return a shared_ptr to a new instance of
   * distance::distance_access_code_tag_ff.
   *
   * To avoid accidental use of raw pointers,
   * distance::distance_access_code_tag_ff's constructor is in a private
   * implementation class. distance::distance_access_code_tag_ff::make is the
   * public interface for creating new instances.
   */
  static sptr make(int symbols, int bps, float distance,
                   unsigned long long code);
};

} // namespace distance
} // namespace gr

#endif /* INCLUDED_DISTANCE_DISTANCE_ACCESS_CODE_TAG_FF_H */
