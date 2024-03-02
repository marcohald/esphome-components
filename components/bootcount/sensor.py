import esphome.codegen as cg
import esphome.config_validation as cv
from esphome.components import sensor
from esphome.const import *

debug_ns = cg.esphome_ns.namespace("debug")
BootcountSensor = debug_ns.class_("BootcountSensor", sensor.Sensor, cg.PollingComponent)

CONFIG_SCHEMA = sensor.sensor_schema(
    BootcountSensor,
    unit_of_measurement=UNIT_EMPTY,
    icon=ICON_EMPTY,
    accuracy_decimals=0,
    state_class=STATE_CLASS_TOTAL,
    device_class=DEVICE_CLASS_EMPTY,
    entity_category=ENTITY_CATEGORY_NONE,
)


async def to_code(config):
    var = await sensor.new_sensor(config)
    await cg.register_component(var, config)
