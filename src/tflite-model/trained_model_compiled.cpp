/* Generated by Edge Impulse
*
* Permission is hereby granted, free of charge, to any person obtaining a copy
* of this software and associated documentation files (the "Software"), to deal
* in the Software without restriction, including without limitation the rights
* to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
* copies of the Software, and to permit persons to whom the Software is
* furnished to do so, subject to the following conditions:
*
* The above copyright notice and this permission notice shall be included in
* all copies or substantial portions of the Software.
*
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
* IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
* FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
* AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
* LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
* OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
* SOFTWARE.
*/
// Generated on: 12.10.2020 13:12:55

#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include "edge-impulse-sdk/tensorflow/lite/c/builtin_op_data.h"
#include "edge-impulse-sdk/tensorflow/lite/c/common.h"
#include "edge-impulse-sdk/tensorflow/lite/micro/kernels/micro_ops.h"

#if defined __GNUC__
#define ALIGN(X) __attribute__((aligned(X)))
#elif defined _MSC_VER
#define ALIGN(X) __declspec(align(X))
#elif defined __TASKING__
#define ALIGN(X) __align(X)
#endif

namespace {

constexpr int kTensorArenaSize = 144;
uint8_t* tensor_arena = NULL;
static uint8_t* current_location;
static uint8_t* tensor_boundary;
template <int SZ, class T> struct TfArray {
  int sz; T elem[SZ];
};
enum used_operators_e {
  OP_FULLY_CONNECTED, OP_SOFTMAX,  OP_LAST
};
struct TensorInfo_t { // subset of TfLiteTensor used for initialization from constant memory
  TfLiteAllocationType allocation_type;
  TfLiteType type;
  void* data;
  TfLiteIntArray* dims;
  size_t bytes;
  TfLiteQuantization quantization;
};
struct NodeInfo_t { // subset of TfLiteNode used for initialization from constant memory
  struct TfLiteIntArray* inputs;
  struct TfLiteIntArray* outputs;
  void* builtin_data;
  used_operators_e used_op_index;
};

TfLiteContext ctx{};
TfLiteTensor tflTensors[11];
TfLiteRegistration registrations[OP_LAST];
TfLiteNode tflNodes[4];

const TfArray<2, int> tensor_dimension0 = { 2, { 1,33 } };
const TfArray<1, float> quant0_scale = { 1, { 0.10960588604211807, } };
const TfArray<1, int> quant0_zero = { 1, { -128 } };
const TfLiteAffineQuantization quant0 = { (TfLiteFloatArray*)&quant0_scale, (TfLiteIntArray*)&quant0_zero, 0 };
const ALIGN(8) int32_t tensor_data1[20] = { -33, -66, 1028, -169, 1086, -101, 599, 1981, -17, -237, 518, -143, 876, 128, -165, 1386, -142, -192, 606, -60, };
const TfArray<1, int> tensor_dimension1 = { 1, { 20 } };
const TfArray<1, float> quant1_scale = { 1, { 0.00062072055879980326, } };
const TfArray<1, int> quant1_zero = { 1, { 0 } };
const TfLiteAffineQuantization quant1 = { (TfLiteFloatArray*)&quant1_scale, (TfLiteIntArray*)&quant1_zero, 0 };
const ALIGN(8) int32_t tensor_data2[10] = { 390, -9, -87, 513, 68, -28, -62, -57, -1, -42, };
const TfArray<1, int> tensor_dimension2 = { 1, { 10 } };
const TfArray<1, float> quant2_scale = { 1, { 0.0012448341585695744, } };
const TfArray<1, int> quant2_zero = { 1, { 0 } };
const TfLiteAffineQuantization quant2 = { (TfLiteFloatArray*)&quant2_scale, (TfLiteIntArray*)&quant2_zero, 0 };
const ALIGN(8) int32_t tensor_data3[4] = { 297, -181, 2, -37, };
const TfArray<1, int> tensor_dimension3 = { 1, { 4 } };
const TfArray<1, float> quant3_scale = { 1, { 0.0018302833195775747, } };
const TfArray<1, int> quant3_zero = { 1, { 0 } };
const TfLiteAffineQuantization quant3 = { (TfLiteFloatArray*)&quant3_scale, (TfLiteIntArray*)&quant3_zero, 0 };
const ALIGN(8) int8_t tensor_data4[20*33] = { 
  -17, -22, -5, 17, 2, 38, -40, -32, 14, -9, 60, -19, -53, 56, 47, 45, 48, -17, 29, -20, 46, -79, 60, -40, -31, -15, -52, 42, -8, -30, -41, -65, 1, 
  1, 6, -7, -29, 4, 48, 30, 41, -53, 31, 24, -34, -20, -56, -40, -30, -28, -55, 36, 21, -11, -39, -53, -40, 13, -40, 8, 21, -37, -3, 43, 48, -61, 
  14, 28, -38, 35, 43, 0, -18, -6, -39, 43, -38, -2, 61, 12, 63, 16, -3, 10, 20, -98, 123, 81, -50, 97, -45, 50, 19, 4, -7, -114, -85, 98, -64, 
  -66, -32, -54, 12, 5, 7, -52, 6, 4, 46, -7, -58, -10, 20, -8, -38, -22, -20, 54, 30, -63, -42, 45, -23, -22, 34, -7, -26, 38, 1, -13, 27, -6, 
  -19, 65, -61, 51, 40, 48, -9, -14, -12, -50, 6, 21, 95, 7, -15, 58, 4, 20, -34, -16, -21, 33, -9, 44, 9, -1, 42, 20, 21, -42, -23, -11, -43, 
  60, 6, 20, 18, 26, 35, 15, 38, 17, 18, 13, -12, 38, 1, 52, 20, -10, 11, 80, 95, 48, -26, -13, 19, -45, 20, 47, 3, 75, 38, 41, 69, 46, 
  -49, 61, -14, -11, -10, 9, 24, -18, -35, 24, -46, -61, -35, -60, 48, 9, -8, 44, 8, -49, -34, -15, 61, -34, 22, 18, -22, 5, 12, -36, 29, -2, -31, 
  -39, 42, -59, -24, -75, -1, -19, -65, 49, -58, 16, -86, -1, -90, -11, -6, 16, -36, 5, -75, -94, -89, -13, 9, 37, 7, 62, 1, -3, 41, -127, 15, -82, 
  37, 51, 41, -37, 39, 8, -29, -6, 37, 29, -78, 37, -12, -32, -55, -37, 12, -18, 57, -47, 17, -14, -26, -10, -43, 40, -41, 20, 62, -16, -28, 34, -29, 
  17, 30, 27, 55, -49, 18, -18, -18, 36, 24, 24, -22, -74, -9, 10, -37, 21, 48, 105, -46, 12, -66, 17, 48, 63, -22, 7, -10, 103, 83, 5, 29, 32, 
  -27, -59, -30, -3, 33, 10, 4, 48, 71, -67, -23, 46, -10, 35, 19, -49, -19, 75, 28, -29, -126, -70, 79, -85, 14, 75, -26, 44, 32, -43, 75, -8, -59, 
  39, 19, -13, -21, -7, 39, -2, 33, 37, 48, -21, 37, -5, -49, -51, 14, -1, 15, 44, 34, 28, -30, -19, 3, 23, -57, -21, 30, -48, 24, -59, 16, -43, 
  3, 15, -10, -30, 31, -13, 19, -15, -20, 15, -33, -17, -12, 55, 65, -36, 34, 32, -43, -23, -116, -16, 79, -30, -21, 25, -52, 12, 25, -19, 37, -22, -45, 
  -6, 24, -30, 32, 15, -8, 54, -9, 6, 20, 46, 50, 70, -27, 17, 20, -34, -30, -13, 24, -87, -27, 32, -18, -45, 58, 21, 5, 33, -34, -65, 52, 1, 
  -12, -44, 82, 6, 31, 6, 14, 41, 19, 26, -18, 10, -85, 1, 12, -15, -9, -14, 95, 13, 23, 1, -13, 19, 50, 24, -17, 13, 26, 67, 41, 13, 76, 
  -58, 48, -44, 14, -4, 36, -12, -18, -37, -3, -43, 25, 33, -18, 63, -20, 11, 58, 20, 27, 1, -9, 25, -32, -13, -13, 35, 14, -16, -27, -64, -37, -47, 
  -68, 19, 13, 18, -38, 21, -35, -34, -39, 15, -47, -42, -37, -46, -40, 16, 26, -25, -51, 13, 17, -95, -25, 32, 43, 18, -25, 5, 42, 85, 2, -3, -32, 
  -38, -23, -66, -44, 53, -9, 6, 37, -91, 53, 21, 36, -4, -3, -24, -14, 6, -36, -7, 77, 2, 9, 27, -60, 47, -28, -31, 41, 36, 53, 35, 11, 23, 
  -9, 71, 72, 105, 67, 71, 41, -21, 5, -94, -58, 15, 123, 41, 53, 98, 27, 61, -44, -26, -31, -36, 34, 114, 11, 24, 77, 36, 33, -12, 66, 41, 61, 
  12, 65, 69, 23, 47, -5, 23, -33, 67, 109, 22, 59, 18, 5, 50, 25, 13, -82, 2, 19, 52, 77, 31, -2, 21, 27, -2, 52, -48, -60, -64, -42, 64, 
};
const TfArray<2, int> tensor_dimension4 = { 2, { 20,33 } };
const TfArray<1, float> quant4_scale = { 1, { 0.0056632044725120068, } };
const TfArray<1, int> quant4_zero = { 1, { 0 } };
const TfLiteAffineQuantization quant4 = { (TfLiteFloatArray*)&quant4_scale, (TfLiteIntArray*)&quant4_zero, 0 };
const ALIGN(8) int8_t tensor_data5[10*20] = { 
  -11, -1, 42, 5, 65, -18, -32, 90, -51, -64, -18, -30, 38, 33, -39, 24, -41, -11, 10, 1, 
  -22, 4, -18, 12, 7, 2, 23, -15, -12, -27, 4, -27, -9, -16, -27, -35, -14, 21, 12, -30, 
  -12, 24, 55, -18, 11, 20, 7, -41, 70, 34, -27, -3, 5, -23, 26, -9, 14, 47, -16, -10, 
  -29, -9, 7, -21, 37, 4, 73, 127, 25, -17, 42, 10, 23, -26, -7, 55, -13, 0, 4, -35, 
  20, 6, -15, -26, -7, 40, 29, -54, -24, 49, 31, -39, 4, 25, 5, 16, -18, -25, 69, 24, 
  17, 25, -30, 2, -23, -14, 4, -10, 28, -37, -38, 28, -27, 12, -23, 23, -27, 0, -35, 19, 
  21, -12, 23, 22, 55, -14, -36, -34, 10, 12, -28, 15, -21, 0, -19, 3, 6, -21, 41, -17, 
  -21, 27, -25, -32, -7, -15, -6, -31, 25, 14, 23, 25, -8, -5, -16, -16, -19, 9, -29, 8, 
  -19, 18, 7, 14, 60, -10, 16, -83, -11, -31, 29, 20, 34, 32, -13, 17, -45, 14, 12, -3, 
  -14, 15, 47, 22, -18, 36, 15, -37, 46, -5, -28, 22, -36, -10, -16, 13, 49, 39, 7, 34, 
};
const TfArray<2, int> tensor_dimension5 = { 2, { 10,20 } };
const TfArray<1, float> quant5_scale = { 1, { 0.012845953926444054, } };
const TfArray<1, int> quant5_zero = { 1, { 0 } };
const TfLiteAffineQuantization quant5 = { (TfLiteFloatArray*)&quant5_scale, (TfLiteIntArray*)&quant5_zero, 0 };
const ALIGN(8) int8_t tensor_data6[4*10] = { 
  48, -5, -42, 99, -54, -17, -89, -2, -14, -8, 
  31, -5, -6, -22, -9, 12, 39, -28, 33, 33, 
  -127, -45, -58, 14, 46, 22, -10, -5, 20, -42, 
  -83, 41, 80, -21, 12, -1, 1, -40, -51, 65, 
};
const TfArray<2, int> tensor_dimension6 = { 2, { 4,10 } };
const TfArray<1, float> quant6_scale = { 1, { 0.012770076282322407, } };
const TfArray<1, int> quant6_zero = { 1, { 0 } };
const TfLiteAffineQuantization quant6 = { (TfLiteFloatArray*)&quant6_scale, (TfLiteIntArray*)&quant6_zero, 0 };
const TfArray<2, int> tensor_dimension7 = { 2, { 1,20 } };
const TfArray<1, float> quant7_scale = { 1, { 0.096904762089252472, } };
const TfArray<1, int> quant7_zero = { 1, { -128 } };
const TfLiteAffineQuantization quant7 = { (TfLiteFloatArray*)&quant7_scale, (TfLiteIntArray*)&quant7_zero, 0 };
const TfArray<2, int> tensor_dimension8 = { 2, { 1,10 } };
const TfArray<1, float> quant8_scale = { 1, { 0.14332595467567444, } };
const TfArray<1, int> quant8_zero = { 1, { -128 } };
const TfLiteAffineQuantization quant8 = { (TfLiteFloatArray*)&quant8_scale, (TfLiteIntArray*)&quant8_zero, 0 };
const TfArray<2, int> tensor_dimension9 = { 2, { 1,4 } };
const TfArray<1, float> quant9_scale = { 1, { 0.26798269152641296, } };
const TfArray<1, int> quant9_zero = { 1, { -3 } };
const TfLiteAffineQuantization quant9 = { (TfLiteFloatArray*)&quant9_scale, (TfLiteIntArray*)&quant9_zero, 0 };
const TfArray<2, int> tensor_dimension10 = { 2, { 1,4 } };
const TfArray<1, float> quant10_scale = { 1, { 0.00390625, } };
const TfArray<1, int> quant10_zero = { 1, { -128 } };
const TfLiteAffineQuantization quant10 = { (TfLiteFloatArray*)&quant10_scale, (TfLiteIntArray*)&quant10_zero, 0 };
const TfLiteFullyConnectedParams opdata0 = { kTfLiteActRelu, kTfLiteFullyConnectedWeightsFormatDefault, false, false };
const TfArray<3, int> inputs0 = { 3, { 0,4,1 } };
const TfArray<1, int> outputs0 = { 1, { 7 } };
const TfLiteFullyConnectedParams opdata1 = { kTfLiteActRelu, kTfLiteFullyConnectedWeightsFormatDefault, false, false };
const TfArray<3, int> inputs1 = { 3, { 7,5,2 } };
const TfArray<1, int> outputs1 = { 1, { 8 } };
const TfLiteFullyConnectedParams opdata2 = { kTfLiteActNone, kTfLiteFullyConnectedWeightsFormatDefault, false, false };
const TfArray<3, int> inputs2 = { 3, { 8,6,3 } };
const TfArray<1, int> outputs2 = { 1, { 9 } };
const TfLiteSoftmaxParams opdata3 = { 1 };
const TfArray<1, int> inputs3 = { 1, { 9 } };
const TfArray<1, int> outputs3 = { 1, { 10 } };
const TensorInfo_t tensorData[] = {
  { kTfLiteArenaRw, kTfLiteInt8, tensor_arena + 0, (TfLiteIntArray*)&tensor_dimension0, 33, {kTfLiteAffineQuantization, const_cast<void*>(static_cast<const void*>(&quant0))}, },
  { kTfLiteMmapRo, kTfLiteInt32, (void*)tensor_data1, (TfLiteIntArray*)&tensor_dimension1, 80, {kTfLiteAffineQuantization, const_cast<void*>(static_cast<const void*>(&quant1))}, },
  { kTfLiteMmapRo, kTfLiteInt32, (void*)tensor_data2, (TfLiteIntArray*)&tensor_dimension2, 40, {kTfLiteAffineQuantization, const_cast<void*>(static_cast<const void*>(&quant2))}, },
  { kTfLiteMmapRo, kTfLiteInt32, (void*)tensor_data3, (TfLiteIntArray*)&tensor_dimension3, 16, {kTfLiteAffineQuantization, const_cast<void*>(static_cast<const void*>(&quant3))}, },
  { kTfLiteMmapRo, kTfLiteInt8, (void*)tensor_data4, (TfLiteIntArray*)&tensor_dimension4, 660, {kTfLiteAffineQuantization, const_cast<void*>(static_cast<const void*>(&quant4))}, },
  { kTfLiteMmapRo, kTfLiteInt8, (void*)tensor_data5, (TfLiteIntArray*)&tensor_dimension5, 200, {kTfLiteAffineQuantization, const_cast<void*>(static_cast<const void*>(&quant5))}, },
  { kTfLiteMmapRo, kTfLiteInt8, (void*)tensor_data6, (TfLiteIntArray*)&tensor_dimension6, 40, {kTfLiteAffineQuantization, const_cast<void*>(static_cast<const void*>(&quant6))}, },
  { kTfLiteArenaRw, kTfLiteInt8, tensor_arena + 48, (TfLiteIntArray*)&tensor_dimension7, 20, {kTfLiteAffineQuantization, const_cast<void*>(static_cast<const void*>(&quant7))}, },
  { kTfLiteArenaRw, kTfLiteInt8, tensor_arena + 0, (TfLiteIntArray*)&tensor_dimension8, 10, {kTfLiteAffineQuantization, const_cast<void*>(static_cast<const void*>(&quant8))}, },
  { kTfLiteArenaRw, kTfLiteInt8, tensor_arena + 16, (TfLiteIntArray*)&tensor_dimension9, 4, {kTfLiteAffineQuantization, const_cast<void*>(static_cast<const void*>(&quant9))}, },
  { kTfLiteArenaRw, kTfLiteInt8, tensor_arena + 0, (TfLiteIntArray*)&tensor_dimension10, 4, {kTfLiteAffineQuantization, const_cast<void*>(static_cast<const void*>(&quant10))}, },
};const NodeInfo_t nodeData[] = {
  { (TfLiteIntArray*)&inputs0, (TfLiteIntArray*)&outputs0, const_cast<void*>(static_cast<const void*>(&opdata0)), OP_FULLY_CONNECTED, },
  { (TfLiteIntArray*)&inputs1, (TfLiteIntArray*)&outputs1, const_cast<void*>(static_cast<const void*>(&opdata1)), OP_FULLY_CONNECTED, },
  { (TfLiteIntArray*)&inputs2, (TfLiteIntArray*)&outputs2, const_cast<void*>(static_cast<const void*>(&opdata2)), OP_FULLY_CONNECTED, },
  { (TfLiteIntArray*)&inputs3, (TfLiteIntArray*)&outputs3, const_cast<void*>(static_cast<const void*>(&opdata3)), OP_SOFTMAX, },
};
static std::vector<void*> overflow_buffers;
static TfLiteStatus AllocatePersistentBuffer(struct TfLiteContext* ctx,
                                                 size_t bytes, void** ptr) {
  if (current_location - bytes < tensor_boundary) {
    // OK, this will look super weird, but.... we have CMSIS-NN buffers which
    // we cannot calculate beforehand easily.
    *ptr = malloc(bytes);
    if (*ptr == NULL) {
      printf("ERR: Failed to allocate persistent buffer of size %u\n", bytes);
      return kTfLiteError;
    }
    overflow_buffers.push_back(*ptr);
    return kTfLiteOk;
  }

  current_location -= bytes;

  *ptr = current_location;
  return kTfLiteOk;
}
typedef struct {
  size_t bytes;
  void *ptr;
} scratch_buffer_t;
static std::vector<scratch_buffer_t> scratch_buffers;

static TfLiteStatus RequestScratchBufferInArena(struct TfLiteContext* ctx, size_t bytes,
                                                int* buffer_idx) {
  scratch_buffer_t b;
  b.bytes = bytes;

  TfLiteStatus s = AllocatePersistentBuffer(ctx, b.bytes, &b.ptr);
  if (s != kTfLiteOk) {
    return s;
  }

  scratch_buffers.push_back(b);

  *buffer_idx = scratch_buffers.size() - 1;

  return kTfLiteOk;
}

static void* GetScratchBuffer(struct TfLiteContext* ctx, int buffer_idx) {
  if (buffer_idx > static_cast<int>(scratch_buffers.size()) - 1) {
    return NULL;
  }
  return scratch_buffers[buffer_idx].ptr;
}
} // namespace

  TfLiteStatus trained_model_init( void*(*alloc_fnc)(size_t,size_t) ) {
  tensor_arena = (uint8_t*) alloc_fnc(16, kTensorArenaSize);
  current_location = tensor_arena + kTensorArenaSize;
  tensor_boundary = tensor_arena;
  ctx.AllocatePersistentBuffer = &AllocatePersistentBuffer;
  ctx.RequestScratchBufferInArena = &RequestScratchBufferInArena;
  ctx.GetScratchBuffer = &GetScratchBuffer;
  ctx.tensors = tflTensors;
  ctx.tensors_size = 11;
  for(size_t i = 0; i < 11; ++i) {
    tflTensors[i].type = tensorData[i].type;
    tflTensors[i].is_variable = 0;
    tflTensors[i].allocation_type = tensorData[i].allocation_type;
    tflTensors[i].bytes = tensorData[i].bytes;
    tflTensors[i].dims = tensorData[i].dims;
    if(tflTensors[i].allocation_type == kTfLiteArenaRw){
      uint8_t* start = (uint8_t*) ((uintptr_t)tensorData[i].data + (uintptr_t) tensor_arena);
      uint8_t* end = start + tensorData[i].bytes;

     tflTensors[i].data.data =  start;

     if (end > tensor_boundary) {
       tensor_boundary = end;
     }
    }
    else{
       tflTensors[i].data.data = tensorData[i].data;
    }
    tflTensors[i].quantization = tensorData[i].quantization;
    if (tflTensors[i].quantization.type == kTfLiteAffineQuantization) {
      TfLiteAffineQuantization const* quant = ((TfLiteAffineQuantization const*)(tensorData[i].quantization.params));
      tflTensors[i].params.scale = quant->scale->data[0];
      tflTensors[i].params.zero_point = quant->zero_point->data[0];
    }
  }
  registrations[OP_FULLY_CONNECTED] = *tflite::ops::micro::Register_FULLY_CONNECTED();
  registrations[OP_SOFTMAX] = *tflite::ops::micro::Register_SOFTMAX();

  for(size_t i = 0; i < 4; ++i) {
    tflNodes[i].inputs = nodeData[i].inputs;
    tflNodes[i].outputs = nodeData[i].outputs;
    tflNodes[i].builtin_data = nodeData[i].builtin_data;
    tflNodes[i].custom_initial_data = nullptr;
    tflNodes[i].custom_initial_data_size = 0;
    if (registrations[nodeData[i].used_op_index].init) {
      tflNodes[i].user_data = registrations[nodeData[i].used_op_index].init(&ctx, (const char*)tflNodes[i].builtin_data, 0);
    }
  }
  for(size_t i = 0; i < 4; ++i) {
    if (registrations[nodeData[i].used_op_index].prepare) {
      TfLiteStatus status = registrations[nodeData[i].used_op_index].prepare(&ctx, &tflNodes[i]);
      if (status != kTfLiteOk) {
        return status;
      }
    }
  }
  return kTfLiteOk;
}

static const int inTensorIndices[] = {
  0, 
};
TfLiteTensor* trained_model_input(int index) {
  return &ctx.tensors[inTensorIndices[index]];
}

static const int outTensorIndices[] = {
  10, 
};
TfLiteTensor* trained_model_output(int index) {
  return &ctx.tensors[outTensorIndices[index]];
}

TfLiteStatus trained_model_invoke() {
  for(size_t i = 0; i < 4; ++i) {
    TfLiteStatus status = registrations[nodeData[i].used_op_index].invoke(&ctx, &tflNodes[i]);
    if (status != kTfLiteOk) {
      return status;
    }
  }
  return kTfLiteOk;
}

TfLiteStatus trained_model_reset( void (*free_fnc)(void* ptr) ) {
  free_fnc(tensor_arena);
  scratch_buffers.clear();
  for (size_t ix = 0; ix < overflow_buffers.size(); ix++) {
    free(overflow_buffers[ix]);
  }
  overflow_buffers.clear();
  return kTfLiteOk;
}