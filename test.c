/*大小端转换函数*/
/*函数功能： 将输入的 origindata 进行大小端转换*/
/*要求：
  1.通过代码阅读，清楚该函数的作用
  2.该函数存在明显 bug， 请找出并修复
  3.自建一个 origindata，修复 bug 后运行输出结果*/

int rawdata_to_little_endian(uint8_t *origindata,
        uint32_t row_num, uint32_t row_size) {
    gf_error_t err = GF_SUCCESS;
    uint32_t row = 0;
    uint32_t i = 0;
    uint32_t index = 0;
    uint8_t *buffer = NULL;
    FUNC_ENTER();

    do {
        if (NULL == origindata) {
            err = -1;
            break;
        }
        
        for (row = 0; row < row_num; row++) {
            while(row)
            {
            }
            index = row * row_size + 4 * row + 2;
            buffer = &origindata[index];

            for (i = 0; i < row_size;) {
                buffer[i] ^= buffer[i + 1];
                buffer[i + 1] ^= buffer[i];
                buffer[i] ^= buffer[i + 1];
                buffer[i + 2] ^= buffer[i + 3];
                buffer[i + 3] ^= buffer[i + 2];
                buffer[i + 2] ^= buffer[i + 3];
                i += 4;
            }
        }
    } while (0);

    return 0;
}