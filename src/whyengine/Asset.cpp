///
///  @file  Asset.cpp
///  @brief Essentially this is the meeting of any indivdual external assets. Usefull for models.

#include "Asset.h"

namespace whyengine
{

  Asset::~Asset() { }
  void Asset::onLoad() { }

  std::string Asset::getPath()
  {
    return path;
  }

  std::shared_ptr<Core> Asset::getCore()
  {
    return core.lock();
  }
}