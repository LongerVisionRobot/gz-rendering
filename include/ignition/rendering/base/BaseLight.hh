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
#ifndef _IGNITION_RENDERING_BASELIGHT_HH_
#define _IGNITION_RENDERING_BASELIGHT_HH_

#include "ignition/rendering/Light.hh"

namespace ignition
{
  namespace rendering
  {
    template <class T>
    class IGNITION_VISIBLE BaseLight :
      public virtual Light,
      public virtual T
    {
      protected: BaseLight();

      public: virtual ~BaseLight();

      public: virtual void SetDiffuseColor(double _r, double _g, double _b,
                  double _a = 1.0);

      public: virtual void SetDiffuseColor(const gazebo::common::Color &_color) = 0;

      public: virtual void SetSpecularColor(double _r, double _g, double _b,
                  double _a = 1.0);

      public: virtual void SetSpecularColor(const gazebo::common::Color &_color) = 0;

      public: virtual void SetAttenuationConstant(double _weight) = 0;

      public: virtual void SetAttenuationLinear(double _weight) = 0;

      public: virtual void SetAttenuationQuadratic(double _weight) = 0;

      public: virtual void SetAttenuationRange(double _range) = 0;

      public: virtual void SetCastShadows(bool _castShadows) = 0;

      protected: virtual void Reset();
    };

    template <class T>
    class IGNITION_VISIBLE BaseDirectionalLight :
      public virtual DirectionalLight,
      public virtual T
    {
      protected: BaseDirectionalLight();

      public: virtual ~BaseDirectionalLight();

      public: virtual void SetDirection(double _x, double _y, double _z);

      public: virtual void SetDirection(const gazebo::math::Vector3 &_dir) = 0;

      protected: virtual void Reset();
    };

    template <class T>
    class IGNITION_VISIBLE BasePointLight :
      public virtual PointLight,
      public virtual T
    {
      protected: BasePointLight();

      public: virtual ~BasePointLight();
    };

    template <class T>
    class IGNITION_VISIBLE BaseSpotLight :
      public virtual SpotLight,
      public virtual T
    {
      protected: BaseSpotLight();

      public: virtual ~BaseSpotLight();

      public: virtual void SetDirection(double _x, double _y, double _z);

      public: virtual void SetDirection(const gazebo::math::Vector3 &_dir) = 0;

      public: virtual void SetInnerAngle(double _radians);

      public: virtual void SetInnerAngle(const gazebo::math::Angle &_angle) = 0;

      public: virtual void SetOuterAngle(double _radians);

      public: virtual void SetOuterAngle(const gazebo::math::Angle &_angle) = 0;

      public: virtual void SetFalloff(double _falloff) = 0;

      protected: virtual void Reset();
    };

    //////////////////////////////////////////////////
    template <class T>
    BaseLight<T>::BaseLight()
    {
    }

    //////////////////////////////////////////////////
    template <class T>
    BaseLight<T>::~BaseLight()
    {
    }

    //////////////////////////////////////////////////
    template <class T>
    void BaseLight<T>::SetDiffuseColor(double _r, double _g, double _b,
        double _a)
    {
      this->SetDiffuseColor(gazebo::common::Color(_r, _g, _b, _a));
    }

    //////////////////////////////////////////////////
    template <class T>
    void BaseLight<T>::SetSpecularColor(double _r, double _g, double _b,
        double _a)
    {
      this->SetSpecularColor(gazebo::common::Color(_r, _g, _b, _a));
    }

    //////////////////////////////////////////////////
    template <class T>
    void BaseLight<T>::Reset()
    {
      this->SetDiffuseColor(gazebo::common::Color::White);
      this->SetSpecularColor(gazebo::common::Color::White);
      this->SetAttenuationConstant(1);
      this->SetAttenuationLinear(0);
      this->SetAttenuationQuadratic(0);
      this->SetAttenuationRange(100);
      this->SetCastShadows(true);
    }

    //////////////////////////////////////////////////
    template <class T>
    BaseDirectionalLight<T>::BaseDirectionalLight()
    {
    }

    //////////////////////////////////////////////////
    template <class T>
    BaseDirectionalLight<T>::~BaseDirectionalLight()
    {
    }

    //////////////////////////////////////////////////
    template <class T>
    void BaseDirectionalLight<T>::SetDirection(double _x, double _y, double _z)
    {
      this->SetDirection(gazebo::math::Vector3(_x, _y, _z));
    }

    //////////////////////////////////////////////////
    template <class T>
    void BaseDirectionalLight<T>::Reset()
    {
      T::Reset();
      this->SetDirection(0, 0, -1);
    }

    //////////////////////////////////////////////////
    template <class T>
    BasePointLight<T>::BasePointLight()
    {
    }

    //////////////////////////////////////////////////
    template <class T>
    BasePointLight<T>::~BasePointLight()
    {
    }

    //////////////////////////////////////////////////
    template <class T>
    BaseSpotLight<T>::BaseSpotLight()
    {
    }

    //////////////////////////////////////////////////
    template <class T>
    BaseSpotLight<T>::~BaseSpotLight()
    {
    }

    //////////////////////////////////////////////////
    template <class T>
    void BaseSpotLight<T>::SetDirection(double _x, double _y, double _z)
    {
      this->SetDirection(gazebo::math::Vector3(_x, _y, _z));
    }

    //////////////////////////////////////////////////
    template <class T>
    void BaseSpotLight<T>::SetInnerAngle(double _radians)
    {
      this->SetInnerAngle(gazebo::math::Angle(_radians));
    }

    //////////////////////////////////////////////////
    template <class T>
    void BaseSpotLight<T>::SetOuterAngle(double _radians)
    {
      this->SetOuterAngle(gazebo::math::Angle(_radians));
    }

    //////////////////////////////////////////////////
    template <class T>
    void BaseSpotLight<T>::Reset()
    {
      T::Reset();
      this->SetDirection(0, 0, -1);
      this->SetInnerAngle(M_PI / 4.5);
      this->SetOuterAngle(M_PI / 4.0);
      this->SetFalloff(1.0);
    }

  }
}
#endif