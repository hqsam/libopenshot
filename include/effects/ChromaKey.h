/**
 * @file
 * @brief Header file for ChromaKey class
 * @author Jonathan Thomas <jonathan@openshot.org>
 *
 * @section LICENSE
 *
 * Copyright (c) 2008-2013 OpenShot Studios, LLC
 * (http://www.openshotstudios.com). This file is part of
 * OpenShot Library (http://www.openshot.org), an open-source project
 * dedicated to delivering high quality video editing and animation solutions
 * to the world.
 *
 * OpenShot Library is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * OpenShot Library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with OpenShot Library.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef OPENSHOT_CHROMAKEY_EFFECT_H
#define OPENSHOT_CHROMAKEY_EFFECT_H

#include "../EffectBase.h"

#include <cmath>
#include <ctime>
#include <iostream>
#include <omp.h>
#include <stdio.h>
#include <tr1/memory>
#include "Magick++.h"
#include "../Color.h"
#include "../Exceptions.h"
#include "../KeyFrame.h"

using namespace std;

namespace openshot
{

	/**
	 * @brief This class uses the ImageMagick++ libraries, to remove (i.e. key out) a color (i.e. greenscreen)
	 *
	 * The greenscreen / bluescreen effect replaces matching colors in the video image with
	 * transparent pixels, revealing lower layers in the timeline.
	 */
	class ChromaKey : public EffectBase
	{
	private:
		Color color;
		Keyframe fuzz;

	public:

		/// Default constructor, which takes an openshot::Color object and a 'fuzz' factor, which
		/// is used to determine how similar colored pixels are matched. The higher the fuzz, the
		/// more colors are matched.
		///
		/// @param color The color to match
		/// @param fuzz The fuzz factor (or threshhold)
		ChromaKey(Color color, Keyframe fuzz);

		/// @brief This method is required for all derived classes of EffectBase, and returns a
		/// modified openshot::Frame object
		///
		/// The frame object is passed into this method, and a frame_number is passed in which
		/// tells the effect which settings to use from it's keyframes (starting at 1).
		///
		/// @returns The modified openshot::Frame object
		/// @param frame The frame object that needs the effect applied to it
		/// @param frame_number The frame number (starting at 1) of the effect on the timeline.
		tr1::shared_ptr<Frame> GetFrame(tr1::shared_ptr<Frame> frame, int frame_number);
	};

}

#endif
