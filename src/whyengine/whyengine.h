/// \brief MASTER HEADER. Complilation of all headers for main.cpp
/// \author George Jennings
/// \version 1.0
/// \date 15/1/21 Updated to include NCCA standards
/// Revision History :
/// Initial Version pre 01/12/20
/// \todo ...


#ifndef WHYENGINE_WHYENGINE_H
#define WHYENGINE_WHYENGINE_H

// system include
#include <rend/rend.h>
#include <iostream>

// header include (Master header compilation of all headers)
#include "Core.h"
#include "Entity.h"
#include "Component.h"
#include "Renderer.h"
#include "Exception.h"
#include "Keyboard.h"
#include "Keymapping.h"
#include "Transform.h"
#include "Model.h"
#include "Asset.h"
#include "Assets.h"
#include "Camera.h"

#include "Sound.h"
#include "SoundSource.h"

#include "Collision.h"

using namespace whyengine;

#endif // _WHYENGINE_H_