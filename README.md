# esphome-components

This repository contains a collection of my custom components
for [ESPHome](https://esphome.io/).

## 1. Usage

Use latest [ESPHome](https://esphome.io/) (at least v1.18.0)
with external components and add this to your `.yaml` definition:

```yaml
external_components:
  - source: github://marcohald/esphome-components
```

## 2. Components

### 2.1. `bootcount`

A component to get the reboot count from the offical ota module. 

Keep in mind to change the reboot_timeout to a value that suits your needs. 
After the time the counter is reset to 0. The Timer is reset on every reboot. 

num_attempts may also needs to be changed.
After this Counter is reached the recovery is entered.

#### 2.1.1. Example

```yaml
ota:
  reboot_timeout: 3min
  num_attempts: 20

sensor:  
  - platform: bootcount
    name: bootcount
```