// Copyright (C) 2026 Free Software Foundation, Inc.
//
// This file is part of the GNU ISO C++ Library.  This library is free
// software; you can redistribute it and/or modify it under the
// terms of the GNU General Public License as published by the
// Free Software Foundation; either version 3, or (at your option)
// any later version.
//
// This library is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License along
// with this library; see the file COPYING3.  If not see
// <http://www.gnu.org/licenses/>.

// { dg-do compile { target c++23 } }

#include <limits>

std::float_denorm_style s; // { dg-warning "is deprecated" }
auto a = std::numeric_limits<float>::has_denorm; // { dg-warning "is deprecated" }
auto b = std::numeric_limits<float>::has_denorm_loss; // { dg-warning "is deprecated" }
auto c = std::numeric_limits<int>::has_denorm; // { dg-warning "is deprecated" }
auto d = std::numeric_limits<int>::has_denorm_loss; // { dg-warning "is deprecated" }

// { dg-prune-output "declared here" }
