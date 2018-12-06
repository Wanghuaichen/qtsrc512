// Copyright 2017 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef SERVICES_SERVICE_MANAGER_ZYGOTE_COMMON_COMMON_SANDBOX_SUPPORT_LINUX_H_
#define SERVICES_SERVICE_MANAGER_ZYGOTE_COMMON_COMMON_SANDBOX_SUPPORT_LINUX_H_

#include <stddef.h>

#include "base/component_export.h"
#include "build/build_config.h"

namespace service_manager {

#if !defined(OS_NACL_NONSFI)
// Returns a file descriptor for a shared memory segment.  The
// executable flag indicates that the caller intends to use mprotect
// with PROT_EXEC after making a mapping, but not that it intends to
// mmap with PROT_EXEC in the first place.  (Some systems, such as
// ChromeOS, disallow PROT_EXEC in mmap on /dev/shm files but do allow
// PROT_EXEC in mprotect on mappings from such files.  This function
// can yield an object that has that constraint.)
COMPONENT_EXPORT(SERVICE_MANAGER_ZYGOTE)
int MakeSharedMemorySegmentViaIPC(size_t length, bool executable);
#endif

// Gets the well-known file descriptor on which we expect to find the
// sandbox IPC channel.
COMPONENT_EXPORT(SERVICE_MANAGER_ZYGOTE) int GetSandboxFD();

}  // namespace service_manager

#endif  // SERVICES_SERVICE_MANAGER_ZYGOTE_COMMON_COMMON_SANDBOX_SUPPORT_LINUX_H_