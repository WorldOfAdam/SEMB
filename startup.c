#include <stdint.h>

#include <stdint.h>

#define SRAM_START  0x20000000U                  /* Inicio da SRAM CORTEX-M */
#define SRAM_SIZE   (128U * 1024U)               /* Tam. SRAM STM32F411 128K */
#define SRAM_END    ((SRAM_START) + (SRAM_SIZE)) /* Final da SRAM STM32F411 */

#define STACK_START SRAM_END                     /* Inicio da Stack */


void reset_handler     (void);
void nmi_handler       (void) __attribute__ ((weak, alias("default_handler")));
void hardfault_handler (void) __attribute__ ((weak, alias("default_handler")));
void memmanage_handler (void) __attribute__ ((weak, alias("default_handler")));
void busfault_handler  (void) __attribute__ ((weak, alias("default_handler")));
void usagefault_handler(void) __attribute__ ((weak, alias("default_handler")));
void svc_handler       (void) __attribute__ ((weak, alias("default_handler")));
void debugmon_handler  (void) __attribute__ ((weak, alias("default_handler")));
void pendsv_handler    (void) __attribute__ ((weak, alias("default_handler")));
void systick_handler   (void) __attribute__ ((weak, alias("default_handler")));
void wwdg_irqhandler   (void) __attribute__ ((weak, alias("default_handler")));
void exti16_handler    (void) __attribute__ ((weak, alias("default_handler")));
void exti21_handler    (void) __attribute__ ((weak, alias("default_handler")));
void exti22_handler    (void) __attribute__ ((weak, alias("default_handler")));
void flash_handler     (void) __attribute__ ((weak, alias("default_handler")));
void rcc_handler       (void) __attribute__ ((weak, alias("default_handler")));
void exti0_handler     (void) __attribute__ ((weak, alias("default_handler")));
void exti1_handler     (void) __attribute__ ((weak, alias("default_handler")));
void exti2_handler     (void) __attribute__ ((weak, alias("default_handler")));
void exti3_handler     (void) __attribute__ ((weak, alias("default_handler")));
void exti4_handler     (void) __attribute__ ((weak, alias("default_handler")));
void dma1s0_handler    (void) __attribute__ ((weak, alias("default_handler")));
void dma1s1_handler    (void) __attribute__ ((weak, alias("default_handler")));
void dma1s2_handler    (void) __attribute__ ((weak, alias("default_handler")));
void dma1s3_handler    (void) __attribute__ ((weak, alias("default_handler")));
void dma1s4_handler    (void) __attribute__ ((weak, alias("default_handler")));
void dma1s5_handler    (void) __attribute__ ((weak, alias("default_handler")));
void dma1s6_handler    (void) __attribute__ ((weak, alias("default_handler")));
void adc_handler       (void) __attribute__ ((weak, alias("default_handler")));
void exti9_handler     (void) __attribute__ ((weak, alias("default_handler")));
void tim19_handler     (void) __attribute__ ((weak, alias("default_handler")));
void tim110_handler    (void) __attribute__ ((weak, alias("default_handler")));
void tim111_handler    (void) __attribute__ ((weak, alias("default_handler")));
void tim1CC_handler    (void) __attribute__ ((weak, alias("default_handler")));
void tim2_handler      (void) __attribute__ ((weak, alias("default_handler")));
void tim3_handler      (void) __attribute__ ((weak, alias("default_handler")));
void tim4_handler      (void) __attribute__ ((weak, alias("default_handler")));
void i2c1ev_handler    (void) __attribute__ ((weak, alias("default_handler")));
void i2c1er_handler    (void) __attribute__ ((weak, alias("default_handler")));
void i2c2ev_handler    (void) __attribute__ ((weak, alias("default_handler")));
void i2c2er_handler    (void) __attribute__ ((weak, alias("default_handler")));
void spi1_handler      (void) __attribute__ ((weak, alias("default_handler")));
void spi2_handler      (void) __attribute__ ((weak, alias("default_handler")));
void usart1_handler    (void) __attribute__ ((weak, alias("default_handler")));
void usart2_handler    (void) __attribute__ ((weak, alias("default_handler")));
void extii15_handler   (void) __attribute__ ((weak, alias("default_handler")));
void exti117rtc_handler(void) __attribute__ ((weak, alias("default_handler")));
void extii18otg_handler(void) __attribute__ ((weak, alias("default_handler")));
void dma1s7_handler    (void) __attribute__ ((weak, alias("default_handler")));
void sdio_handler      (void) __attribute__ ((weak, alias("default_handler")));
void tim5_handler      (void) __attribute__ ((weak, alias("default_handler")));
void spi3_handler      (void) __attribute__ ((weak, alias("default_handler")));
void dma2s0_handler    (void) __attribute__ ((weak, alias("default_handler")));
void dma2s1_handler    (void) __attribute__ ((weak, alias("default_handler")));
void dma2s2_handler    (void) __attribute__ ((weak, alias("default_handler")));
void dm2s3_handler     (void) __attribute__ ((weak, alias("default_handler")));
void dma2s4_handler    (void) __attribute__ ((weak, alias("default_handler")));
void otg_handler       (void) __attribute__ ((weak, alias("default_handler")));
void dma2s5_handler    (void) __attribute__ ((weak, alias("default_handler")));
void dma2s6_handler    (void) __attribute__ ((weak, alias("default_handler")));
void dma2s7_handler    (void) __attribute__ ((weak, alias("default_handler")));
void usart6_handler    (void) __attribute__ ((weak, alias("default_handler")));
void i2c3ev_handler    (void) __attribute__ ((weak, alias("default_handler")));
void i2c3er_handler    (void) __attribute__ ((weak, alias("default_handler")));
void fpu_handler       (void) __attribute__ ((weak, alias("default_handler")));
void spi4_handler      (void) __attribute__ ((weak, alias("default_handler")));
void spi5_handler      (void) __attribute__ ((weak, alias("default_handler")));


extern uint32_t _sdata;     /* Inicio da secao .data */
extern uint32_t _edata;     /* Fim da secao .data */
extern uint32_t _la_data;   /* Endereco de carga na RAM da secao .data */

extern uint32_t _sbss;      /* Inicio da secao .bss */
extern uint32_t _ebss;      /* Fim da secao .bss */

uint32_t vectors[] __attribute__((section(".isr_vectors"))) =
{
  STACK_START,                            /* 0x0000 0000 */
  (uint32_t)reset_handler,                /* 0x0000 0004 */
  (uint32_t)nmi_handler,                  /* 0x0000 0008 */
  (uint32_t)hardfault_handler,            /* 0x0000 000c */
  (uint32_t)memmanage_handler,            /* 0x0000 0010 */
  (uint32_t)busfault_handler,             /* 0x0000 0014 */
  (uint32_t)usagefault_handler,           /* 0x0000 0018 */
  0,                                      /* 0x0000 001c */
  0,                                      /* 0x0000 0020 */
  0,                                      /* 0x0000 0024 */
  0,                                      /* 0x0000 0028 */
  (uint32_t)svc_handler,                  /* 0x0000 002c */
  (uint32_t)debugmon_handler,             /* 0x0000 0030 */
  0,                                      /* 0x0000 0034 */
  (uint32_t)pendsv_handler,               /* 0x0000 0038 */
  (uint32_t)systick_handler,              /* 0x0000 003c */
  (uint32_t)wwdg_irqhandler,              /* 0x0000 0040 */
  (uint32_t)exti16_handler,               /* 0x0000 0044*/
  (uint32_t)exti21_handler,               /* 0x0000 0048*/
  (uint32_t)exti22_handler,               /* 0x0000 004c*/
  (uint32_t)flash_handler,                /* 0x0000 0050*/
  (uint32_t)rcc_handler,                  /* 0x0000 0054*/
  (uint32_t)exti0_handler,                /* 0x0000 0058*/
  (uint32_t)exti1_handler,                /* 0x0000 005c*/
  (uint32_t)exti2_handler,                /* 0x0000 0060*/
  (uint32_t)exti3_handler,                /* 0x0000 0064*/
  (uint32_t)exti4_handler,                /* 0x0000 0068*/
  (uint32_t)dma1s0_handler,               /* 0x0000 006c*/
  (uint32_t)dma1s1_handler,               /* 0x0000 0070*/
  (uint32_t)dma1s2_handler,               /* 0x0000 0074*/
  (uint32_t)dma1s3_handler,               /* 0x0000 0078*/
  (uint32_t)dma1s4_handler,               /* 0x0000 007c*/
  (uint32_t)dma1s5_handler,               /* 0x0000 0080*/
  (uint32_t)dma1s6_handler,               /* 0x0000 0084*/
  (uint32_t)adc_handler,                  /* 0x0000 0088*/
  (uint32_t)exti9_handler,                /* 0x0000 008c*/
  (uint32_t)tim19_handler,                /* 0x0000 00A0*/
  (uint32_t)tim110_handler,               /* 0x0000 00A4*/
  (uint32_t)tim111_handler,               /* 0x0000 00A8*/
  (uint32_t)tim1CC_handler,               /* 0x0000 00AC*/
  (uint32_t)tim2_handler,                 /* 0x0000 00B0*/
  (uint32_t)tim3_handler,                 /* 0x0000 00B4*/
  (uint32_t)tim4_handler,                 /* 0x0000 00B8*/
  (uint32_t)i2c1ev_handler,               /* 0x0000 00BC*/
  (uint32_t)i2c1er_handler,               /* 0x0000 00C0*/
  (uint32_t)i2c2ev_handler,               /* 0x0000 00C4*/
  (uint32_t)i2c2er_handler,               /* 0x0000 00C8*/
  (uint32_t)spi1_handler,                 /* 0x0000 00CC*/
  (uint32_t)spi2_handler,                 /* 0x0000 00D0*/
  (uint32_t)usart1_handler,               /* 0x0000 00D4*/
  (uint32_t)usart2_handler,               /* 0x0000 00D8*/
  0,                                      /* 0x0000 00DC*/
  (uint32_t)extii15_handler,              /* 0x0000 00E0*/
  (uint32_t)exti117rtc_handler,           /* 0X0000 00E4*/
  (uint32_t)extii18otg_handler,           /* 0x0000 00E8*/
  0,                                      /* 0X0000 00EC*/
  0,                                      /* 0X0000 00F0*/
  0,                                      /* 0X0000 00F4*/
  0,                                      /* 0X0000 00F8*/
  (uint32_t)dma1s7_handler,               /* 0X0000 00FC*/
  0,                                      /* 0x0000 0100*/
  (uint32_t)sdio_handler,                 /* 0x0000 0104*/
  (uint32_t)tim5_handler,                  /* 0X0000 0108*/
  (uint32_t)spi3_handler,                 /* 0X0000 010C*/
  0,                                      /* 0X0000 0110*/
  0,                                      /* 0X0000 0114*/
  0,                                      /* 0X0000 0118*/
  0,                                      /* 0X0000 011C*/
  (uint32_t)dma2s0_handler,               /* 0X0000 0120*/
  (uint32_t)dma2s1_handler,               /* 0X0000 0124*/
  (uint32_t)dma2s2_handler,               /* 0X0000 0128*/
  (uint32_t)dm2s3_handler,                /* 0X0000 012C*/
  (uint32_t)dma2s4_handler,               /* 0X0000 0130*/
  0,                                      /* 0X0000 0134*/
  0,                                      /* 0X0000 0138*/
  0,                                      /* 0X0000 013C*/
  0,                                      /* 0X0000 0140*/
  0,                                      /* 0X0000 0144*/
  0,                                      /* 0X0000 0148*/  
  (uint32_t)otg_handler,                  /* 0X0000 014C*/
  (uint32_t)dma2s5_handler,               /* 0X0000 0150*/
  (uint32_t)dma2s6_handler,               /* 0X0000 0154*/
  (uint32_t)dma2s7_handler,               /* 0X0000 0158*/
  (uint32_t)usart6_handler,               /* 0X0000 015C*/
  (uint32_t)i2c3ev_handler,               /* 0X0000 0160*/
  (uint32_t)i2c3er_handler,               /* 0X0000 0164*/
  0,                                      /* 0X0000 0168*/  
  0,                                      /* 0X0000 016C*/  
  0,                                      /* 0X0000 0170*/  
  0,                                      /* 0X0000 0174*/  
  0,                                      /* 0X0000 0178*/  
  0,                                      /* 0X0000 017C*/
  0,                                      /* 0X0000 0180*/  
  (uint32_t)fpu_handler,                  /* 0x0000 0184*/
  0,                                      /* 0X0000 0188*/  
  0,                                      /* 0X0000 018C*/  
  (uint32_t)spi4_handler,                 /* 0x0000 0190*/
  (uint32_t)spi5_handler,                 /* 0x0000 0194*/
};

void reset_handler(void)
{
    /*Carrega seca data da FLASH para a SRAM*/
  uint32_t size = (uint32_t)&_edata - (uint32_t)&_sdata;
  uint8_t *pDst = (uint8_t*)&_sdata;                      /* SRAM */
  uint8_t *pSrc = (uint8_t*)&_la_data;                    /* FLASH */
  
  uint32_t i;
  for(i = 0; i < size; i++)
  {
    *pDst++ = *pSrc++;
  }
   /* Preenche a secao .bss com zero */

  size = (uint32_t)&_ebss - (uint32_t)&_sbss;
  pDst = (uint8_t*)&_sbss;
  for(i = 0 ; i < size; i++)
  {
    *pDst++ = 0;
  }

  /* Chama a funcao main() */

  main();
}
void default_handler(void)
{
    while (1);
    
}

