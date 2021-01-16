///
///  @file  Asset.cpp
///  @brief Essentially this is the meeting of any indivdual external assets. Usefull for models.

//  header includes
#include "Asset.h"

namespace whyengine
{

  Asset::~Asset() { } // the two virtual functions (  destructor then regular function  )
  void Asset::onLoad() { }

  std::string Asset::getPath()
  {
    return path;  // returns the path system value
  }

  std::shared_ptr<Core> Asset::getCore()
  {
    return core.lock(); // locks all objects that are passed as arguments
  }
}