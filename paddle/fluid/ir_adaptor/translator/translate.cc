// Copyright (c) 2023 PaddlePaddle Authors. All Rights Reserved.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include "paddle/fluid/ir_adaptor/translator/translate.h"

#include <memory>

#include "paddle/fluid/framework/program_desc.h"
#include "paddle/fluid/ir/dialect/pd_dialect.h"
#include "paddle/fluid/ir_adaptor/translator/program_translator.h"
#include "paddle/ir/core/program.h"

namespace paddle {

using LegacyProgramDesc = ::paddle::framework::ProgramDesc;
using Program = ::ir::Program;

std::unique_ptr<Program> TranslateLegacyProgramToProgram(
    const LegacyProgramDesc& legacy_program) {
  auto program = std::make_unique<Program>(ir::IrContext::Instance());

  translator::ProgramTranslator program_translator(&legacy_program,
                                                   program.get());
  program_translator.Translate();

  return program;
}

}  // namespace paddle