Check DALI + FASTLed combination:
//- FASTLED RMT Driver + UART DMA  - N/A - ESP32 Uart is not flex enough (Start bit and 8bit data)
- FASTLED RMT BUILTIN Driver + RMT RX for DALI
- FASTLED RMT Driver + GPIO for DALI
- FASTLED RMT Driver + Custom RMT Rx for DALI

Figure out how to handle reception of backward frame's