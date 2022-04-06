/* Includes ------------------------------------------------------------------*/

#include "stc3115_I2C.h"
#include "stc3115_Driver.h"

#include <string.h>

#include <nrf_drv_twi.h>
#include <nrf_error.h>

#include "app_i2c.h"

/* External I2C R/W interface ------------------------------------------------*/

/**
 * @brief       Utility function to write several bytes to STC311x registers
 * @param[in]   NumberOfBytes
 * @param[in]   RegAddress
 * @param[in]   TxBuffer
 * @return
 *              - (-1): Unexpected error
 *              - 0: Success
 */
int I2C_Write(int NumberOfBytes, int RegAddress, unsigned char *TxBuffer) {
    int ret = -1;
    uint8_t tx_item[sizeof(uint8_t) + NumberOfBytes];
    memset(tx_item, 0, sizeof tx_item);
    memcpy(tx_item, &RegAddress, sizeof(uint8_t));
    memcpy(tx_item + sizeof(uint8_t), TxBuffer, NumberOfBytes);
    ret = nrf_drv_twi_tx(   &m_twi,
                            STC3115_SLAVE_ADDRESS_7BIT,
                            tx_item,
                            sizeof tx_item,
                            false);
    if (ret != NRF_SUCCESS) {
        ret = -1;
    }
    return (int)ret;
}

/**
 * @brief       Utility function to read several bytes from STC311x registers
 * @param[in]   NumberOfBytes
 * @param[in]   RegAddress
 * @param[out]  RxBuffer
 * @return
 *              - (-1): Unexpected error
 *              - 0: Success
 */
int I2C_Read(int NumberOfBytes, int RegAddress, unsigned char *RxBuffer) {
    int ret = -1;
    ret = nrf_drv_twi_tx(   &m_twi,
                            STC3115_SLAVE_ADDRESS_7BIT,
                            (uint8_t *)&RegAddress,
                            sizeof(uint8_t),
                            true);
    if (ret != NRF_SUCCESS) {
        return -1;
    }
    ret = nrf_drv_twi_rx(   &m_twi,
                            STC3115_SLAVE_ADDRESS_7BIT,
                            RxBuffer,
                            NumberOfBytes);
    if (ret != NRF_SUCCESS) {
        ret = -1;
    }
    return (int)ret;
}
