#include "bootcount_sensor.h"
#include "esphome/core/log.h"
#include "esphome/core/helpers.h"
#include "esphome/core/hal.h"

namespace esphome {
namespace debug {

static const char *const TAG = "Bootcount";
void BootcountSensor::read() {

  this->bootcountPreference = global_preferences->make_preference<uint32_t>(233825507UL, false);
  int32_t val;
  if (!this->bootcountPreference.load(&val))
    ESP_LOGD(TAG, "%s: %d", "read_bootcount failed", val);  
    this->publish_state(-1);
  ESP_LOGD(TAG, "%s: %d", "read_bootcount success", val);
  this->publish_state(val);
}

void BootcountSensor::update() {
}
void BootcountSensor::setup() {

  ESP_LOGD(TAG, "%s:", "Setup");
  this->read();
}
std::string BootcountSensor::unique_id() { return get_mac_address() + "-bootcount"; }
float BootcountSensor::get_setup_priority() const { return setup_priority::HARDWARE; }
void BootcountSensor::dump_config() { LOG_SENSOR("", "Bootcount Sensor", this); }

}  // namespace debug
}  // namespace esphome
