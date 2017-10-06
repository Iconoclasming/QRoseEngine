#pragma once

#ifdef _DEBUG
#define QRE_ASSERT(expr, message) { static_assert(expr, message); }
#else
#define QRE_ASSERT(expr, message) {}
#endif