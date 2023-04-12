#include "customcode_9IelyHyJdbU3dIHGQW8qHD.h"
#ifdef __cplusplus
extern "C" {
#endif


/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
DLL_EXPORT_CC extern const char_T *get_dll_checksum_9IelyHyJdbU3dIHGQW8qHD(void);
DLL_EXPORT_CC extern char_T bmp3_init_9IelyHyJdbU3dIHGQW8qHD(struct bmp3_dev *dev);
DLL_EXPORT_CC extern char_T bmp3_soft_reset_9IelyHyJdbU3dIHGQW8qHD(struct bmp3_dev *dev);
DLL_EXPORT_CC extern char_T bmp3_set_sensor_settings_9IelyHyJdbU3dIHGQW8qHD(uint32_T desired_settings, struct bmp3_dev *dev);
DLL_EXPORT_CC extern char_T bmp3_get_sensor_settings_9IelyHyJdbU3dIHGQW8qHD(struct bmp3_dev *dev);
DLL_EXPORT_CC extern char_T bmp3_set_op_mode_9IelyHyJdbU3dIHGQW8qHD(struct bmp3_dev *dev);
DLL_EXPORT_CC extern char_T bmp3_get_op_mode_9IelyHyJdbU3dIHGQW8qHD(uint8_T *op_mode, struct bmp3_dev *dev);
DLL_EXPORT_CC extern char_T bmp3_get_sensor_data_9IelyHyJdbU3dIHGQW8qHD(uint8_T sensor_comp, struct bmp3_data *data, struct bmp3_dev *dev);
DLL_EXPORT_CC extern char_T bmp3_set_regs_9IelyHyJdbU3dIHGQW8qHD(uint8_T *reg_addr, const uint8_T *reg_data, uint32_T len, struct bmp3_dev *dev);
DLL_EXPORT_CC extern char_T bmp3_get_regs_9IelyHyJdbU3dIHGQW8qHD(uint8_T reg_addr, uint8_T *reg_data, uint32_T len, struct bmp3_dev *dev);
DLL_EXPORT_CC extern char_T bmp3_set_fifo_settings_9IelyHyJdbU3dIHGQW8qHD(uint16_T desired_settings, struct bmp3_dev *dev);
DLL_EXPORT_CC extern char_T bmp3_get_fifo_settings_9IelyHyJdbU3dIHGQW8qHD(struct bmp3_dev *dev);
DLL_EXPORT_CC extern char_T bmp3_get_fifo_data_9IelyHyJdbU3dIHGQW8qHD(struct bmp3_dev *dev);
DLL_EXPORT_CC extern char_T bmp3_get_fifo_length_9IelyHyJdbU3dIHGQW8qHD(uint16_T *fifo_length, struct bmp3_dev *dev);
DLL_EXPORT_CC extern char_T bmp3_extract_fifo_data_9IelyHyJdbU3dIHGQW8qHD(struct bmp3_data *data, struct bmp3_dev *dev);
DLL_EXPORT_CC extern char_T bmp3_set_fifo_watermark_9IelyHyJdbU3dIHGQW8qHD(struct bmp3_dev *dev);
DLL_EXPORT_CC extern char_T bmp3_fifo_flush_9IelyHyJdbU3dIHGQW8qHD(struct bmp3_dev *dev);
DLL_EXPORT_CC extern char_T bmp3_get_status_9IelyHyJdbU3dIHGQW8qHD(struct bmp3_dev *dev);

/* Function Definitions */
DLL_EXPORT_CC const uint8_T *get_checksum_source_info(int32_T *size);
#ifdef __cplusplus
}
#endif

