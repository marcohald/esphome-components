#pragma once

#include "esphome/core/component.h"
#include "esphome/core/preferences.h"
#include "esphome/components/sensor/sensor.h"

namespace esphome {
namespace debug {

class BootcountSensor : public sensor::Sensor, public PollingComponent {
 public:
  void update() override;
  void read();
  void setup() override;
  void dump_config() override;

  float get_setup_priority() const override;

  std::string unique_id() override;


 protected:
  ESPPreferenceObject bootcountPreference;
};

}  // namespace debug
}  // namespace esphome
