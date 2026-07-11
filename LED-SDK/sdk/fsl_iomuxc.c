#include "fsl_iomuxc.h"

void IOMUXC_SetPinMux(uint32_t muxRegister, uint32_t muxMode)
{
    *(volatile uint32_t *)(uintptr_t)muxRegister = muxMode;
}

void IOMUXC_SetPinConfig(uint32_t muxRegister, uint32_t configValue)
{
    *(volatile uint32_t *)(uintptr_t)muxRegister = configValue;
}
