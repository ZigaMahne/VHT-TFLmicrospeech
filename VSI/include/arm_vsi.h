/*
 * Copyright (c) 2021 Arm Limited. All rights reserved.
 */

/*
 * Virtual Streaming Interface (VSI)
 */



#ifndef __ARM_VSI_H
#define __ARM_VSI_H

#ifdef __cplusplus
extern "C" {
#endif

#ifndef __IM
#define __IM  volatile const    /*! Defines 'read only' structure member permissions */
#endif
#ifndef __OM
#define __OM  volatile          /*! Defines 'write only' structure member permissions */
#endif
#ifndef __IOM
#define __IOM volatile          /*! Defines 'read/write' structure member permissions */
#endif

#include <stdint.h>


/* IRQ number assignment (should be moved to device header) */
#define ARM_VSI0_IRQn   224
#define ARM_VSI1_IRQn   225
#define ARM_VSI2_IRQn   226
#define ARM_VSI3_IRQn   227
#define ARM_VSI4_IRQn   228
#define ARM_VSI5_IRQn   229
#define ARM_VSI6_IRQn   230
#define ARM_VSI7_IRQn   231

/**
  \brief  Structure type to access the virtual streaming interface.
 */
typedef struct
{
  __IOM uint32_t Data[0x2000];  /*!< Offset: 0x0000 (R/W) Data Buffer (32KB) */
  __IOM uint32_t Regs[32];      /*!< Offset: 0x8000 (R/W) User Registers */
  struct {
    __IOM uint32_t Control;     /*!< Offset: 0x8080 (R/W) Timer Control Register */
    __IOM uint32_t Interval;    /*!< Offset: 0x8084 (R/W) Timer Interval Value (in microseconds) */
    __IM  uint32_t Count;       /*!< Offset: 0x8088 (R/ ) Timer Overflow Count */
  } Timer;                      /*!< Time counter with 1MHz input frequency */                      
  struct {
    __IOM uint32_t Control;     /*!< Offset: 0x808C (R/W) DMA Control */
    __IOM uint32_t Address;     /*!< Offset: 0x8090 (R/W) DMA Memory Start Address */
    __IOM uint32_t BlockSize;   /*!< Offset: 0x8094 (R/W) DMA Block Size (in bytes) */
    __IOM uint32_t BlockNum;    /*!< Offset: 0x8098 (R/W) DMA Number of Blocks (must be 2^n) */
    __IM  uint32_t BlockIndex;  /*!< Offset: 0x809C (R/ ) DMA Block Index */
  } DMA;                        /*!< DMA Controller */                      
  __IOM uint32_t IRQ;           /*!< Offset: 0x80A0 (R/W) Interrupt Request */
} ARM_VSI_Type;

/* VSI Timer Control Definitions for Timer.Control register */
#define ARM_VSI_Timer_Run_Pos           0U                                      /*!< Timer Control: Run Position */
#define ARM_VSI_Timer_Run_Msk           (1UL << ARM_VSI_Timer_Run_Pos)          /*!< Timer Control: Run Mask */
#define ARM_VSI_Timer_Periodic_Pos      1U                                      /*!< Timer Control: Periodic Position */
#define ARM_VSI_Timer_Periodic_Msk      (1UL << ARM_VSI_Timer_Periodic_Pos)     /*!< Timer Control: Periodic Mask */
#define ARM_VSI_Timer_Trig_IRQ_Pos      2U                                      /*!< Timer Control: Trig_IRQ Position */
#define ARM_VSI_Timer_Trig_IRQ_Msk      (1UL << ARM_VSI_Timer_Trig_IRQ_Pos)     /*!< Timer Control: Trig_IRQ Mask */

/* VSI DMA Control Definitions for DMA.Control register */
#define ARM_VSI_DMA_Enable_Pos          0U                                      /*!< DMA Control: Enable Position */
#define ARM_VSI_DMA_Enable_Msk          (1UL << ARM_VSI_DMA_Enable_Pos)         /*!< DMA Control: Enable Mask */
#define ARM_VSI_DMA_Direction_Pos       1U                                      /*!< DMA Control: Direction Position */
#define ARM_VSI_DMA_Direction_Msk       (1UL << ARM_VSI_DMA_Direction_Pos)      /*!< DMA Control: Direction Mask */
#define ARM_VSI_DMA_Direction_P2M       (0UL*ARM_VSI_DMA_Direction_Msk)         /*!< DMA Control: Direction P2M */
#define ARM_VSI_DMA_Direction_M2P       (1UL*ARM_VSI_DMA_Direction_Msk)         /*!< DMA Control: Direction M2P */

/* Memory mapping of 8 VSI peripherals */
#define ARM_VSI0_BASE   (0x5FF00000UL)                       /*!< VSI 0 Base Address */
#define ARM_VSI1_BASE   (0x5FF10000UL)                       /*!< VSI 1 Base Address */
#define ARM_VSI2_BASE   (0x5FF20000UL)                       /*!< VSI 2 Base Address */
#define ARM_VSI3_BASE   (0x5FF30000UL)                       /*!< VSI 3 Base Address */
#define ARM_VSI4_BASE   (0x5FF40000UL)                       /*!< VSI 4 Base Address */
#define ARM_VSI5_BASE   (0x5FF50000UL)                       /*!< VSI 5 Base Address */
#define ARM_VSI6_BASE   (0x5FF60000UL)                       /*!< VSI 6 Base Address */
#define ARM_VSI7_BASE   (0x5FF70000UL)                       /*!< VSI 7 Base Address */
#define ARM_VSI0        ((ARM_VSI_Type *)ARM_VSI0_BASE)      /*!< VSI 0 struct */
#define ARM_VSI1        ((ARM_VSI_Type *)ARM_VSI1_BASE)      /*!< VSI 1 struct */
#define ARM_VSI2        ((ARM_VSI_Type *)ARM_VSI2_BASE)      /*!< VSI 2 struct */
#define ARM_VSI3        ((ARM_VSI_Type *)ARM_VSI3_BASE)      /*!< VSI 3 struct */
#define ARM_VSI4        ((ARM_VSI_Type *)ARM_VSI4_BASE)      /*!< VSI 4 struct */
#define ARM_VSI5        ((ARM_VSI_Type *)ARM_VSI5_BASE)      /*!< VSI 5 struct */
#define ARM_VSI6        ((ARM_VSI_Type *)ARM_VSI6_BASE)      /*!< VSI 6 struct */
#define ARM_VSI7        ((ARM_VSI_Type *)ARM_VSI7_BASE)      /*!< VSI 7 struct */


#ifdef __cplusplus
}
#endif

#endif /* __ARM_VSI_H */
