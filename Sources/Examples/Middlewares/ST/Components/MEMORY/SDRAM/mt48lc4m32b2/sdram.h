#ifndef _SDRAM_H_
#define _SDRAM_H_


#include "mt48lc4m32b2.h"

#define BSP_SDRAM_Init                    MT48LC4M32B2B5_Init
#define BSP_SDRAM_DeInit                  MT48LC4M32B2B5_DeInit
#define BSP_SDRAM_Initialization_sequence MT48LC4M32B2B5_Initialization_sequence
#define BSP_SDRAM_ReadData                MT48LC4M32B2B5_ReadData
#define BSP_SDRAM_ReadData_DMA            MT48LC4M32B2B5_ReadData_DMA
#define BSP_SDRAM_WriteData               MT48LC4M32B2B5_WriteData
#define BSP_SDRAM_WriteData_DMA           MT48LC4M32B2B5_WriteData_DMA
#define BSP_SDRAM_Sendcmd                 MT48LC4M32B2B5_Sendcmd
   
/* These functions can be modified in case the current settings (e.g. DMA stream)
   need to be changed for specific application needs */
#define    BSP_SDRAM_MspInit              MT48LC4M32B2B5_MspInit
#define    BSP_SDRAM_MspDeInit            MT48LC4M32B2B5_MspDeInit

#endif /* _SDRAM_H_ */