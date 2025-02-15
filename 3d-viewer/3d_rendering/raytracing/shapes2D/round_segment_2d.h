/*
 * This program source code file is part of KiCad, a free EDA CAD application.
 *
 * Copyright (C) 2015-2016 Mario Luzeiro <mrluzeiro@ua.pt>
 * Copyright The KiCad Developers, see AUTHORS.txt for contributors.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, you may find one here:
 * http://www.gnu.org/licenses/old-licenses/gpl-2.0.html
 * or you may search the http://www.gnu.org website for the version 2 license,
 * or you may write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA
 */

/**
 * @file round_segment_2d.h
 */

#ifndef _ROUND_SEGMENT_2D_H_
#define _ROUND_SEGMENT_2D_H_

#include "object_2d.h"
#include "../ray.h"
#include "filled_circle_2d.h"
#include <plugins/3dapi/xv3d_types.h>   // SFVEC2F

class BOARD_ITEM;

class ROUND_SEGMENT_2D : public OBJECT_2D
{
public:
    ROUND_SEGMENT_2D( const SFVEC2F& aStart, const SFVEC2F& aEnd, float aWidth,
                      const BOARD_ITEM& aBoardItem );

    float GetRadius() const { return m_radius; }
    float GetRadiusSquared() const { return m_radius_squared; }
    float GetWidth()  const { return m_width; }
    float GetLength() const { return m_segment.m_Length; }

    const SFVEC2F& GetStart() const { return m_segment.m_Start; }
    const SFVEC2F& GetEnd() const { return m_segment.m_End; }
    const SFVEC2F& GetEnd_minus_Start() const { return m_segment.m_End_minus_start; }

    const SFVEC2F& GetLeftStar() const { return m_leftStart; }
    const SFVEC2F& GetLeftEnd()  const { return m_leftEnd; }
    const SFVEC2F& GetLeftEnd_minus_Start() const { return m_leftEndMinusStart; }
    const SFVEC2F& GetLeftDir()  const { return m_leftDir; }

    const SFVEC2F& GetRightStar() const { return m_rightStart; }
    const SFVEC2F& GetRightEnd()  const { return m_rightEnd; }
    const SFVEC2F& GetRightEnd_minus_Start() const { return m_rightEndMinusStart; }
    const SFVEC2F& GetRightDir()  const { return m_rightDir; }

    bool Overlaps( const BBOX_2D& aBBox ) const override;
    bool Intersects( const BBOX_2D& aBBox ) const override;
    bool Intersect( const RAYSEG2D& aSegRay, float* aOutT, SFVEC2F* aNormalOut ) const override;
    INTERSECTION_RESULT IsBBoxInside( const BBOX_2D& aBBox ) const override;
    bool IsPointInside( const SFVEC2F& aPoint ) const override;

private:
    friend class ROUND_SEGMENT;

    RAYSEG2D m_segment;

    SFVEC2F  m_leftStart;
    SFVEC2F  m_leftEnd;
    SFVEC2F  m_leftEndMinusStart;
    SFVEC2F  m_leftDir;

    SFVEC2F  m_rightStart;
    SFVEC2F  m_rightEnd;
    SFVEC2F  m_rightEndMinusStart;
    SFVEC2F  m_rightDir;

    float    m_radius;
    float    m_radius_squared;
    float    m_width;
};

static const float s_min_dot = ( FLT_EPSILON * 4.0f * FLT_EPSILON * 4.0f );

/**
 * Check if segment start and end is very close to each other.
 *
 * This should used to check if the segment should be converted to a circle instead.
 *
 * @return true is it is better to convert the segment to circle
 */
inline bool Is_segment_a_circle( const SFVEC2F& aStart, const SFVEC2F& aEnd )
{
    const SFVEC2F vec = aEnd - aStart;

    // This is the same as calc the length squared (without the sqrt)
    // and compare with a small value.
    return (aStart == aEnd) || ( glm::dot( vec, vec ) <= s_min_dot );
}

#endif // _ROUND_SEGMENT_2D_H_
