/*
 * Copyright (C) 2015 Open Source Robotics Foundation
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 */
#ifndef _IGNITION_RENDERING_OPTIXNODE_HH_
#define _IGNITION_RENDERING_OPTIXNODE_HH_

#include "ignition/rendering/base/BaseNode.hh"
#include "ignition/rendering/optix/OptixIncludes.hh"
#include "ignition/rendering/optix/OptixRenderTypes.hh"
#include "ignition/rendering/optix/OptixObject.hh"

namespace ignition
{
  namespace rendering
  {
    class IGNITION_VISIBLE OptixNode :
      public BaseNode<OptixObject>
    {
      protected: OptixNode();

      public: virtual ~OptixNode();

      public: virtual bool HasParent() const;

      public: virtual VisualPtr GetParent() const;

      public: virtual void PreRender();

      public: virtual optix::Transform GetOptixTransform() const;

      protected: virtual gazebo::math::Pose GetRawLocalPose() const;

      protected: virtual void SetRawLocalPose(const gazebo::math::Pose &_pose);

      protected: virtual void WritePoseToDevice();

      protected: virtual void WritePoseToDeviceImpl();

      protected: virtual void SetParent(OptixVisualPtr _parent);

      protected: virtual void Init();

      protected: OptixVisualPtr parent;

      protected: optix::Transform optixTransform;

      protected: optix::Group optixGroup;

      protected: optix::Acceleration optixAccel;

      protected: gazebo::math::Pose pose;

      protected: bool poseDirty;

      private: friend class OptixVisual;
    };
  }
}
#endif