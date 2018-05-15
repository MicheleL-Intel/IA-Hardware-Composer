/*
// Copyright (c) 2016 Intel Corporation
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//      http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
*/
#ifndef WSI_DRMBUFFER_H_
#define WSI_DRMBUFFER_H_

#include <platformdefines.h>

#include "overlaybuffer.h"

namespace hwcomposer {

class NativeBufferHandler;

class DrmBuffer : public OverlayBuffer {
 public:
  DrmBuffer(DrmBuffer&& rhs) = default;
  DrmBuffer& operator=(DrmBuffer&& other) = default;

  DrmBuffer() = default;

  ~DrmBuffer() override;

  void InitializeFromNativeHandle(HWCNativeHandle handle,
                                  ResourceManager* buffer_manager) override;

  uint32_t GetWidth() const override {
    return mtdt.width_;
  }

  uint32_t GetHeight() const override {
    return mtdt.height_;
  }

  uint32_t GetFormat() const override {
    return mtdt.format_;
  }

  HWCLayerType GetUsage() const override {
    return usage_;
  }

  uint32_t GetFb() const override {
    return image_.drm_fd_;
  }

  uint32_t GetPrimeFD() const override {
    return image_.handle_->meta_data_.prime_fds_[0];
  }

  const uint32_t* GetPitches() const override {
    return &mtdt.pitches_[0];
  }

  const uint32_t* GetOffsets() const override {
    return &mtdt.offsets_[0];
  }

  uint32_t GetTilingMode() const override {
    return mtdt.tiling_mode_;
  }

  const ResourceHandle& GetGpuResource(GpuDisplay egl_display,
                                       bool external_import) override;

  const ResourceHandle& GetGpuResource() override;

  const MediaResourceHandle& GetMediaResource(MediaDisplay display,
                                              uint32_t width,
                                              uint32_t height) override;

  bool CreateFrameBuffer() override;

  bool CreateFrameBufferWithModifier(uint64_t modifier) override;

  HWCNativeHandle GetOriginalHandle() const override {
    return original_handle_;
  }

  void SetOriginalHandle(HWCNativeHandle handle) override;

  void Dump() override;

  void SaveMetaDataBufferObject(const HwcBuffer& bo) { mtdt = bo; };

 private:
  void Initialize(const HwcBuffer& bo);
  uint32_t width_ = 0;
  uint32_t height_ = 0;
  uint32_t format_ = 0;
  uint32_t tiling_mode_ = 0;
  uint32_t frame_buffer_format_ = 0;
  HwcBuffer mtdt; /* metadata buffer object */
  HWCLayerType usage_ = kLayerNormal;
  uint32_t previous_width_ = 0;   // For Media usage.
  uint32_t previous_height_ = 0;  // For Media usage.
  ResourceManager* resource_manager_ = 0;
  ResourceHandle image_;
  MediaResourceHandle media_image_;
  HWCNativeHandle original_handle_;
};

}  // namespace hwcomposer
#endif  // WSI_DRMBUFFER_H_
