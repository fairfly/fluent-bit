#include <stdint.h>
#include <ctraces/ctraces.h>
#include <ctraces/ctr_decode_msgpack.h>

int LLVMFuzzerTestOneInput(const uint8_t *data, size_t size){
    size_t off = 0;
    struct ctrace *ctr = NULL;
    size_t msgpack_text_size;
    char *msgpack_text_buffer = NULL;

    ctr_decode_msgpack_create(&ctr, data, size, &off);
    if (ctr != NULL) {
        ctr_encode_msgpack_create(ctr, &msgpack_text_buffer, &msgpack_text_size);
        ctr_encode_msgpack_destroy(msgpack_text_buffer);

        ctr_destroy(ctr);
    }
    return 0;
}
