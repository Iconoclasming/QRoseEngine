#include "QRoseEngine.Core/DebugRender.hpp"

std::shared_ptr<QRose::IDebugRender> QRose::DebugRender::pDebugRender = std::make_shared<NullDebugRender>();