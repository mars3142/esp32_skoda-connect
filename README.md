[![PlatformIO CI](https://github.com/mars3142/esp32_skoda-connect/actions/workflows/platformio.yml/badge.svg?branch=main)](https://github.com/mars3142/esp32_skoda-connect/actions/workflows/platformio.yml)

# URL order

1. OAuth ?
2. Vehicle data: https://api.skoda-connect.com/vehicles
3. Main data (inspection, gas range): https://api.skoda-connect.com/vehicles/[VIN]/services/rvs
4. Doors and lights: https://api.skoda-connect.com/vehicles/[VIN]/services/doors-and-lights
5. Last trip: https://api.skoda-connect.com/vehicles/[VIN]/services/rts/newest
6. Current position: https://api.skoda-connect.com/vehicles/[VIN]/services/cf/position
