/******************************************************************************
 * Copyright 2018 The Apollo Authors. All Rights Reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *****************************************************************************/

/**
 * @file
 */

#ifndef MODEULES_DATA_DATA_COMPONENT_H_
#define MODEULES_DATA_DATA_COMPONENT_H_

#include <memory>
#include <string>

#include "cybertron/common/macros.h"
#include "cybertron/component/timer_component.h"
#include "cybertron/cybertron.h"

#include "modules/data/proto/data.pb.h"
#include "modules/data/proto/data_conf.pb.h"

/**
 * @namespace apollo::data
 * @brief apollo::data
 */
namespace apollo {
namespace data {

class DataComponent final
    : public apollo::cybertron::Component<DataInputCommand> {
 public:
  DataComponent() = default;
  ~DataComponent() = default;
 public:
  bool Init() override;
  bool Proc(const std::shared_ptr<DataInputCommand> &request) override;
  // probably do not need this with Proc function,
  // but leave it for testing for now
  void CreateReader();

 private:
  void OnDataInputCommand(
    const std::shared_ptr<DataInputCommand> &data_input_cmd);
 private:
  DataConf data_conf_;
  std::shared_ptr<apollo::cybertron::Reader<DataInputCommand>>
    data_input_cmd_reader_;
};

CYBERTRON_REGISTER_COMPONENT(DataComponent)

}  // namespace data
}  // namespace apollo

#endif  // MODEULES_DATA_DATA_COMPONENT_H_