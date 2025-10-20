/**
  ***************************************************************************************
  * @file     
  * @author  ljh
  * @version V1.0.0
  * @date    2025/07/18
  * @brief   usb格式化输出

  * @note    
  ***************************************************************************************
  * 版权声明 COPYRIGHT 2025 xxx@126.com
  ***************************************************************************************
**/

#include "usbd_cdc_if.h"
#include "main.h"
#include "stdarg.h"
#include "stdint.h"
#include "stdbool.h"


extern uint8_t UserTxBufferFS[APP_TX_DATA_SIZE];
extern uint8_t UserRxBufferFS[APP_RX_DATA_SIZE];

extern USBD_HandleTypeDef hUsbDeviceFS;

void usb_printf(const char *format,...)
{
    va_list args;
    uint32_t length;
    va_start(args,format);
    length = vsnprintf((char *)UserTxBufferFS,APP_TX_DATA_SIZE,(char *)format,args);
    va_end(args);
    CDC_Transmit_FS(UserTxBufferFS,length);
}