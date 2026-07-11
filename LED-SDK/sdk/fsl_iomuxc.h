#ifndef __FSL_IOMUXC_H
#define __FSL_IOMUXC_H

#include "imx6ull.h"

void IOMUXC_SetPinMux(uint32_t muxRegister, uint32_t muxMode);
void IOMUXC_SetPinConfig(uint32_t muxRegister, uint32_t configValue);

#endif
