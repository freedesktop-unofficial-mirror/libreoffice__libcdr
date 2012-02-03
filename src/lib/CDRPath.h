/* -*- Mode: C++; tab-width: 2; indent-tabs-mode: nil; c-basic-offset: 2 -*- */
/* libcdr
 * Version: MPL 1.1 / GPLv2+ / LGPLv2+
 *
 * The contents of this file are subject to the Mozilla Public License Version
 * 1.1 (the "License"); you may not use this file except in compliance with
 * the License or as specified alternatively below. You may obtain a copy of
 * the License at http://www.mozilla.org/MPL/
 *
 * Software distributed under the License is distributed on an "AS IS" basis,
 * WITHOUT WARRANTY OF ANY KIND, either express or implied. See the License
 * for the specific language governing rights and limitations under the
 * License.
 *
 * Major Contributor(s):
 * Copyright (C) 2012 Fridrich Strba <fridrich.strba@bluewin.ch>
 *
 *
 * All Rights Reserved.
 *
 * For minor contributions see the git repository.
 *
 * Alternatively, the contents of this file may be used under the terms of
 * either the GNU General Public License Version 2 or later (the "GPLv2+"), or
 * the GNU Lesser General Public License Version 2 or later (the "LGPLv2+"),
 * in which case the provisions of the GPLv2+ or the LGPLv2+ are applicable
 * instead of those above.
 */

#ifndef CDRPATH_H
#define CDRPATH_H

#include <vector>
#include <libwpd/libwpd.h>

#include "CDRTypes.h"

namespace libcdr
{

class CDRPathElement
{
public:
  CDRPathElement() {}
  virtual ~CDRPathElement() {}
  virtual void writeOut(WPXPropertyListVector &vec) = 0;
  virtual void transform(const CDRTransform &trafo) = 0;
};


class CDRPath : public CDRPathElement
{
public:
  CDRPath() : m_elements() {}
  ~CDRPath();

  void appendMoveTo(double x, double y);
  void appendLineTo(double x, double y);
  void appendCubicBezierTo(double x1, double y1, double x2, double x3, double x, double y);
  void appendQuadraticBezierTo(double x1, double y1, double x, double y);
  void appendArcTo(double rx, double ry, double rotation, bool longAngle, bool sweep, double x, double y);
  void appendClosePath();
  void appendPath(const CDRPath &path);

  void writeOut(WPXPropertyListVector &vec);
  void transform(const CDRTransform &trafo);

  void clear();
  bool empty();

private:
  std::vector<CDRPathElement *> m_elements;
};

} // namespace libcdr

#endif /* CDRPATH_H */
/* vim:set shiftwidth=2 softtabstop=2 expandtab: */
