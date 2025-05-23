// Copyright 2015-2018 Hans Dembinski
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt
// or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_HISTOGRAM_HPP
#define BOOST_HISTOGRAM_HPP

/**
  \file boost/histogram.hpp
  Includes all standard headers of the Boost.histogram library.

  Extra headers not automatically included are:
    - boost/histogram/accumulators/ostream.hpp
    - boost/histogram/axis/ostream.hpp
    - boost/histogram/ostream.hpp
    - boost/histogram/serialization.hpp
*/

#include <boost/histogram/accumulators/mean.hpp>
#include <boost/histogram/accumulators/sum.hpp>
#include <boost/histogram/accumulators/weighted_mean.hpp>
#include <boost/histogram/accumulators/weighted_sum.hpp>
#include <boost/histogram/algorithm/project.hpp>
#include <boost/histogram/algorithm/reduce.hpp>
#include <boost/histogram/algorithm/sum.hpp>
#include <boost/histogram/axis.hpp>
#include <boost/histogram/histogram.hpp>
#include <boost/histogram/indexed.hpp>
#include <boost/histogram/literals.hpp>
#include <boost/histogram/make_histogram.hpp>
#include <boost/histogram/make_profile.hpp>
#include <boost/histogram/storage_adaptor.hpp>
#include <boost/histogram/unlimited_storage.hpp>

#endif
