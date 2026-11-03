/**
 ******************************************************************************
 * Xenia : Xbox 360 Emulator Research Project                                 *
 ******************************************************************************
 * Released under the BSD license - see LICENSE in the root for more details. *
 ******************************************************************************
 */

#ifndef XENIA_GPU_DIAG_DUMP_H_
#define XENIA_GPU_DIAG_DUMP_H_

#include <cstdint>

namespace xe {
namespace gpu {
namespace diag {

// Diagnostic frame dump (harms-way-diag branch). When active, the D3D12
// command processor and render target cache log every draw, resolve and
// render target ownership transfer of the current guest frame. Only touched
// from the GPU command processor thread.
inline bool frame_dump_active = false;
inline uint64_t frame_dump_frame = 0;
inline uint32_t frame_dump_event = 0;
// When active (only within an active frame dump), every resolve's written
// guest memory range is read back and saved to LocalState\diag.
inline bool resolve_capture_active = false;
// Number of the current guest frame (always updated, not only when dumping).
inline uint64_t current_frame = 0;

}  // namespace diag
}  // namespace gpu
}  // namespace xe

#endif  // XENIA_GPU_DIAG_DUMP_H_
