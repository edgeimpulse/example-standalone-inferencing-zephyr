# SPDX-License-Identifier: Apache-2.0

cmake_minimum_required(VERSION 3.13.1)

find_package(Zephyr HINTS $ENV{ZEPHYR_BASE})
project(hello_world)

zephyr_compile_options(-fdiagnostics-color=always)

add_subdirectory(edge-impulse-sdk/porting/zephyr)

INCLUDE_DIRECTORIES(
	tflite-model
	model-parameters
	# edge-impulse-sdk/utensor/src/uTensor/util
	# edge-impulse-sdk/utensor/src/uTensor/ops/cmsis_ops
	# edge-impulse-sdk/utensor/src/uTensor/ops
	# edge-impulse-sdk/utensor/src/uTensor/loaders
	# edge-impulse-sdk/utensor/src/uTensor/core
	# edge-impulse-sdk/utensor/src/uTensor
	# edge-impulse-sdk/utensor/src
	# edge-impulse-sdk/utensor
	edge-impulse-sdk/third_party/ruy/ruy/profiler
	edge-impulse-sdk/third_party/ruy/ruy
	edge-impulse-sdk/third_party/ruy
	edge-impulse-sdk/third_party/gemmlowp/internal
	edge-impulse-sdk/third_party/gemmlowp/fixedpoint
	edge-impulse-sdk/third_party/gemmlowp
	edge-impulse-sdk/third_party/flatbuffers/include/flatbuffers
	edge-impulse-sdk/third_party/flatbuffers/include
	edge-impulse-sdk/third_party/flatbuffers
	edge-impulse-sdk/third_party
	edge-impulse-sdk/tensorflow/lite/schema
	# edge-impulse-sdk/tensorflow/lite/micro/testing
	edge-impulse-sdk/tensorflow/lite/micro/memory_planner
	edge-impulse-sdk/tensorflow/lite/micro/kernels
	edge-impulse-sdk/tensorflow/lite/micro
	edge-impulse-sdk/tensorflow/lite/kernels/internal/reference/integer_ops
	edge-impulse-sdk/tensorflow/lite/kernels/internal/reference
	edge-impulse-sdk/tensorflow/lite/kernels/internal/optimized
	edge-impulse-sdk/tensorflow/lite/kernels/internal
	edge-impulse-sdk/tensorflow/lite/kernels
	edge-impulse-sdk/tensorflow/lite/core/api
	edge-impulse-sdk/tensorflow/lite/core
	edge-impulse-sdk/tensorflow/lite/c
	edge-impulse-sdk/tensorflow/lite
	edge-impulse-sdk/tensorflow/core/public
	edge-impulse-sdk/tensorflow/core
	edge-impulse-sdk/tensorflow
	edge-impulse-sdk/porting
	#edge-impulse-sdk/porting/zephyr
	edge-impulse-sdk/dsp/speechpy
	edge-impulse-sdk/dsp/spectral
	edge-impulse-sdk/dsp/kissfft
	edge-impulse-sdk/dsp/dct
	edge-impulse-sdk/dsp
	edge-impulse-sdk/classifier
	edge-impulse-sdk/anomaly
	edge-impulse-sdk/CMSIS/NN/Include
	edge-impulse-sdk/CMSIS/NN
	edge-impulse-sdk/CMSIS/DSP/Source/DistanceFunctions
	edge-impulse-sdk/CMSIS/DSP/Source
	edge-impulse-sdk/CMSIS/DSP/PrivateInclude
	edge-impulse-sdk/CMSIS/DSP/Include
	edge-impulse-sdk/CMSIS/DSP
	edge-impulse-sdk/CMSIS/Core/Include
	edge-impulse-sdk/CMSIS/Core
	edge-impulse-sdk/CMSIS
	edge-impulse-sdk
	.
	)
ADD_EXECUTABLE(example-standalone-inferencing-nrf52-zephyr
	edge-impulse-sdk/CMSIS/Core/Include/cachel1_armv7.h
	edge-impulse-sdk/CMSIS/Core/Include/cmsis_armcc.h
	edge-impulse-sdk/CMSIS/Core/Include/cmsis_armclang.h
	edge-impulse-sdk/CMSIS/Core/Include/cmsis_armclang_ltm.h
	edge-impulse-sdk/CMSIS/Core/Include/cmsis_compiler.h
	edge-impulse-sdk/CMSIS/Core/Include/cmsis_gcc.h
	edge-impulse-sdk/CMSIS/Core/Include/cmsis_iccarm.h
	edge-impulse-sdk/CMSIS/Core/Include/cmsis_version.h
	edge-impulse-sdk/CMSIS/Core/Include/core_armv81mml.h
	edge-impulse-sdk/CMSIS/Core/Include/core_armv8mbl.h
	edge-impulse-sdk/CMSIS/Core/Include/core_armv8mml.h
	edge-impulse-sdk/CMSIS/Core/Include/core_cm0.h
	edge-impulse-sdk/CMSIS/Core/Include/core_cm0plus.h
	edge-impulse-sdk/CMSIS/Core/Include/core_cm1.h
	edge-impulse-sdk/CMSIS/Core/Include/core_cm23.h
	edge-impulse-sdk/CMSIS/Core/Include/core_cm3.h
	edge-impulse-sdk/CMSIS/Core/Include/core_cm33.h
	edge-impulse-sdk/CMSIS/Core/Include/core_cm35p.h
	edge-impulse-sdk/CMSIS/Core/Include/core_cm4.h
	edge-impulse-sdk/CMSIS/Core/Include/core_cm55.h
	edge-impulse-sdk/CMSIS/Core/Include/core_cm7.h
	edge-impulse-sdk/CMSIS/Core/Include/core_sc000.h
	edge-impulse-sdk/CMSIS/Core/Include/core_sc300.h
	edge-impulse-sdk/CMSIS/Core/Include/mpu_armv7.h
	edge-impulse-sdk/CMSIS/Core/Include/mpu_armv8.h
	edge-impulse-sdk/CMSIS/Core/Include/pmu_armv8.h
	edge-impulse-sdk/CMSIS/Core/Include/tz_context.h
	edge-impulse-sdk/CMSIS/DSP/Include/arm_common_tables.h
	edge-impulse-sdk/CMSIS/DSP/Include/arm_common_tables_f16.h
	edge-impulse-sdk/CMSIS/DSP/Include/arm_const_structs.h
	edge-impulse-sdk/CMSIS/DSP/Include/arm_const_structs_f16.h
	edge-impulse-sdk/CMSIS/DSP/Include/arm_helium_utils.h
	edge-impulse-sdk/CMSIS/DSP/Include/arm_math.h
	edge-impulse-sdk/CMSIS/DSP/Include/arm_math_f16.h
	edge-impulse-sdk/CMSIS/DSP/Include/arm_mve_tables.h
	edge-impulse-sdk/CMSIS/DSP/Include/arm_mve_tables_f16.h
	edge-impulse-sdk/CMSIS/DSP/Include/arm_vec_math.h
	edge-impulse-sdk/CMSIS/DSP/PrivateInclude/arm_sorting.h
	edge-impulse-sdk/CMSIS/DSP/PrivateInclude/arm_vec_fft.h
	edge-impulse-sdk/CMSIS/DSP/PrivateInclude/arm_vec_filtering.h
	edge-impulse-sdk/CMSIS/DSP/Source/BasicMathFunctions/BasicMathFunctionsF16.c
	edge-impulse-sdk/CMSIS/DSP/Source/BasicMathFunctions/arm_abs_f16.c
	edge-impulse-sdk/CMSIS/DSP/Source/BasicMathFunctions/arm_abs_f32.c
	edge-impulse-sdk/CMSIS/DSP/Source/BasicMathFunctions/arm_abs_q15.c
	edge-impulse-sdk/CMSIS/DSP/Source/BasicMathFunctions/arm_abs_q31.c
	edge-impulse-sdk/CMSIS/DSP/Source/BasicMathFunctions/arm_abs_q7.c
	edge-impulse-sdk/CMSIS/DSP/Source/BasicMathFunctions/arm_add_f16.c
	edge-impulse-sdk/CMSIS/DSP/Source/BasicMathFunctions/arm_add_f32.c
	edge-impulse-sdk/CMSIS/DSP/Source/BasicMathFunctions/arm_add_q15.c
	edge-impulse-sdk/CMSIS/DSP/Source/BasicMathFunctions/arm_add_q31.c
	edge-impulse-sdk/CMSIS/DSP/Source/BasicMathFunctions/arm_add_q7.c
	edge-impulse-sdk/CMSIS/DSP/Source/BasicMathFunctions/arm_and_u16.c
	edge-impulse-sdk/CMSIS/DSP/Source/BasicMathFunctions/arm_and_u32.c
	edge-impulse-sdk/CMSIS/DSP/Source/BasicMathFunctions/arm_and_u8.c
	edge-impulse-sdk/CMSIS/DSP/Source/BasicMathFunctions/arm_dot_prod_f16.c
	edge-impulse-sdk/CMSIS/DSP/Source/BasicMathFunctions/arm_dot_prod_f32.c
	edge-impulse-sdk/CMSIS/DSP/Source/BasicMathFunctions/arm_dot_prod_q15.c
	edge-impulse-sdk/CMSIS/DSP/Source/BasicMathFunctions/arm_dot_prod_q31.c
	edge-impulse-sdk/CMSIS/DSP/Source/BasicMathFunctions/arm_dot_prod_q7.c
	edge-impulse-sdk/CMSIS/DSP/Source/BasicMathFunctions/arm_mult_f16.c
	edge-impulse-sdk/CMSIS/DSP/Source/BasicMathFunctions/arm_mult_f32.c
	edge-impulse-sdk/CMSIS/DSP/Source/BasicMathFunctions/arm_mult_q15.c
	edge-impulse-sdk/CMSIS/DSP/Source/BasicMathFunctions/arm_mult_q31.c
	edge-impulse-sdk/CMSIS/DSP/Source/BasicMathFunctions/arm_mult_q7.c
	edge-impulse-sdk/CMSIS/DSP/Source/BasicMathFunctions/arm_negate_f16.c
	edge-impulse-sdk/CMSIS/DSP/Source/BasicMathFunctions/arm_negate_f32.c
	edge-impulse-sdk/CMSIS/DSP/Source/BasicMathFunctions/arm_negate_q15.c
	edge-impulse-sdk/CMSIS/DSP/Source/BasicMathFunctions/arm_negate_q31.c
	edge-impulse-sdk/CMSIS/DSP/Source/BasicMathFunctions/arm_negate_q7.c
	edge-impulse-sdk/CMSIS/DSP/Source/BasicMathFunctions/arm_not_u16.c
	edge-impulse-sdk/CMSIS/DSP/Source/BasicMathFunctions/arm_not_u32.c
	edge-impulse-sdk/CMSIS/DSP/Source/BasicMathFunctions/arm_not_u8.c
	edge-impulse-sdk/CMSIS/DSP/Source/BasicMathFunctions/arm_offset_f16.c
	edge-impulse-sdk/CMSIS/DSP/Source/BasicMathFunctions/arm_offset_f32.c
	edge-impulse-sdk/CMSIS/DSP/Source/BasicMathFunctions/arm_offset_q15.c
	edge-impulse-sdk/CMSIS/DSP/Source/BasicMathFunctions/arm_offset_q31.c
	edge-impulse-sdk/CMSIS/DSP/Source/BasicMathFunctions/arm_offset_q7.c
	edge-impulse-sdk/CMSIS/DSP/Source/BasicMathFunctions/arm_or_u16.c
	edge-impulse-sdk/CMSIS/DSP/Source/BasicMathFunctions/arm_or_u32.c
	edge-impulse-sdk/CMSIS/DSP/Source/BasicMathFunctions/arm_or_u8.c
	edge-impulse-sdk/CMSIS/DSP/Source/BasicMathFunctions/arm_scale_f16.c
	edge-impulse-sdk/CMSIS/DSP/Source/BasicMathFunctions/arm_scale_f32.c
	edge-impulse-sdk/CMSIS/DSP/Source/BasicMathFunctions/arm_scale_q15.c
	edge-impulse-sdk/CMSIS/DSP/Source/BasicMathFunctions/arm_scale_q31.c
	edge-impulse-sdk/CMSIS/DSP/Source/BasicMathFunctions/arm_scale_q7.c
	edge-impulse-sdk/CMSIS/DSP/Source/BasicMathFunctions/arm_shift_q15.c
	edge-impulse-sdk/CMSIS/DSP/Source/BasicMathFunctions/arm_shift_q31.c
	edge-impulse-sdk/CMSIS/DSP/Source/BasicMathFunctions/arm_shift_q7.c
	edge-impulse-sdk/CMSIS/DSP/Source/BasicMathFunctions/arm_sub_f16.c
	edge-impulse-sdk/CMSIS/DSP/Source/BasicMathFunctions/arm_sub_f32.c
	edge-impulse-sdk/CMSIS/DSP/Source/BasicMathFunctions/arm_sub_q15.c
	edge-impulse-sdk/CMSIS/DSP/Source/BasicMathFunctions/arm_sub_q31.c
	edge-impulse-sdk/CMSIS/DSP/Source/BasicMathFunctions/arm_sub_q7.c
	edge-impulse-sdk/CMSIS/DSP/Source/BasicMathFunctions/arm_xor_u16.c
	edge-impulse-sdk/CMSIS/DSP/Source/BasicMathFunctions/arm_xor_u32.c
	edge-impulse-sdk/CMSIS/DSP/Source/BasicMathFunctions/arm_xor_u8.c
	edge-impulse-sdk/CMSIS/DSP/Source/BayesFunctions/arm_gaussian_naive_bayes_predict_f32.c
	edge-impulse-sdk/CMSIS/DSP/Source/CommonTables/CommonTablesF16.c
	edge-impulse-sdk/CMSIS/DSP/Source/CommonTables/arm_common_tables.c
	edge-impulse-sdk/CMSIS/DSP/Source/CommonTables/arm_common_tables_f16.c
	edge-impulse-sdk/CMSIS/DSP/Source/CommonTables/arm_const_structs.c
	edge-impulse-sdk/CMSIS/DSP/Source/CommonTables/arm_const_structs_f16.c
	edge-impulse-sdk/CMSIS/DSP/Source/CommonTables/arm_mve_tables.c
	edge-impulse-sdk/CMSIS/DSP/Source/CommonTables/arm_mve_tables_f16.c
	edge-impulse-sdk/CMSIS/DSP/Source/ComplexMathFunctions/arm_cmplx_conj_f32.c
	edge-impulse-sdk/CMSIS/DSP/Source/ComplexMathFunctions/arm_cmplx_conj_q15.c
	edge-impulse-sdk/CMSIS/DSP/Source/ComplexMathFunctions/arm_cmplx_conj_q31.c
	edge-impulse-sdk/CMSIS/DSP/Source/ComplexMathFunctions/arm_cmplx_dot_prod_f32.c
	edge-impulse-sdk/CMSIS/DSP/Source/ComplexMathFunctions/arm_cmplx_dot_prod_q15.c
	edge-impulse-sdk/CMSIS/DSP/Source/ComplexMathFunctions/arm_cmplx_dot_prod_q31.c
	edge-impulse-sdk/CMSIS/DSP/Source/ComplexMathFunctions/arm_cmplx_mag_f32.c
	edge-impulse-sdk/CMSIS/DSP/Source/ComplexMathFunctions/arm_cmplx_mag_q15.c
	edge-impulse-sdk/CMSIS/DSP/Source/ComplexMathFunctions/arm_cmplx_mag_q31.c
	edge-impulse-sdk/CMSIS/DSP/Source/ComplexMathFunctions/arm_cmplx_mag_squared_f32.c
	edge-impulse-sdk/CMSIS/DSP/Source/ComplexMathFunctions/arm_cmplx_mag_squared_q15.c
	edge-impulse-sdk/CMSIS/DSP/Source/ComplexMathFunctions/arm_cmplx_mag_squared_q31.c
	edge-impulse-sdk/CMSIS/DSP/Source/ComplexMathFunctions/arm_cmplx_mult_cmplx_f32.c
	edge-impulse-sdk/CMSIS/DSP/Source/ComplexMathFunctions/arm_cmplx_mult_cmplx_q15.c
	edge-impulse-sdk/CMSIS/DSP/Source/ComplexMathFunctions/arm_cmplx_mult_cmplx_q31.c
	edge-impulse-sdk/CMSIS/DSP/Source/ComplexMathFunctions/arm_cmplx_mult_real_f32.c
	edge-impulse-sdk/CMSIS/DSP/Source/ComplexMathFunctions/arm_cmplx_mult_real_q15.c
	edge-impulse-sdk/CMSIS/DSP/Source/ComplexMathFunctions/arm_cmplx_mult_real_q31.c
	edge-impulse-sdk/CMSIS/DSP/Source/ControllerFunctions/arm_pid_init_f32.c
	edge-impulse-sdk/CMSIS/DSP/Source/ControllerFunctions/arm_pid_init_q15.c
	edge-impulse-sdk/CMSIS/DSP/Source/ControllerFunctions/arm_pid_init_q31.c
	edge-impulse-sdk/CMSIS/DSP/Source/ControllerFunctions/arm_pid_reset_f32.c
	edge-impulse-sdk/CMSIS/DSP/Source/ControllerFunctions/arm_pid_reset_q15.c
	edge-impulse-sdk/CMSIS/DSP/Source/ControllerFunctions/arm_pid_reset_q31.c
	edge-impulse-sdk/CMSIS/DSP/Source/ControllerFunctions/arm_sin_cos_f32.c
	edge-impulse-sdk/CMSIS/DSP/Source/ControllerFunctions/arm_sin_cos_q31.c
	edge-impulse-sdk/CMSIS/DSP/Source/DistanceFunctions/arm_boolean_distance.c
	edge-impulse-sdk/CMSIS/DSP/Source/DistanceFunctions/arm_boolean_distance_template.h
	edge-impulse-sdk/CMSIS/DSP/Source/DistanceFunctions/arm_braycurtis_distance_f32.c
	edge-impulse-sdk/CMSIS/DSP/Source/DistanceFunctions/arm_canberra_distance_f32.c
	edge-impulse-sdk/CMSIS/DSP/Source/DistanceFunctions/arm_chebyshev_distance_f32.c
	edge-impulse-sdk/CMSIS/DSP/Source/DistanceFunctions/arm_cityblock_distance_f32.c
	edge-impulse-sdk/CMSIS/DSP/Source/DistanceFunctions/arm_correlation_distance_f32.c
	edge-impulse-sdk/CMSIS/DSP/Source/DistanceFunctions/arm_cosine_distance_f32.c
	edge-impulse-sdk/CMSIS/DSP/Source/DistanceFunctions/arm_dice_distance.c
	edge-impulse-sdk/CMSIS/DSP/Source/DistanceFunctions/arm_euclidean_distance_f32.c
	edge-impulse-sdk/CMSIS/DSP/Source/DistanceFunctions/arm_hamming_distance.c
	edge-impulse-sdk/CMSIS/DSP/Source/DistanceFunctions/arm_jaccard_distance.c
	edge-impulse-sdk/CMSIS/DSP/Source/DistanceFunctions/arm_jensenshannon_distance_f32.c
	edge-impulse-sdk/CMSIS/DSP/Source/DistanceFunctions/arm_kulsinski_distance.c
	edge-impulse-sdk/CMSIS/DSP/Source/DistanceFunctions/arm_minkowski_distance_f32.c
	edge-impulse-sdk/CMSIS/DSP/Source/DistanceFunctions/arm_rogerstanimoto_distance.c
	edge-impulse-sdk/CMSIS/DSP/Source/DistanceFunctions/arm_russellrao_distance.c
	edge-impulse-sdk/CMSIS/DSP/Source/DistanceFunctions/arm_sokalmichener_distance.c
	edge-impulse-sdk/CMSIS/DSP/Source/DistanceFunctions/arm_sokalsneath_distance.c
	edge-impulse-sdk/CMSIS/DSP/Source/DistanceFunctions/arm_yule_distance.c
	edge-impulse-sdk/CMSIS/DSP/Source/FastMathFunctions/arm_cos_f32.c
	edge-impulse-sdk/CMSIS/DSP/Source/FastMathFunctions/arm_cos_q15.c
	edge-impulse-sdk/CMSIS/DSP/Source/FastMathFunctions/arm_cos_q31.c
	edge-impulse-sdk/CMSIS/DSP/Source/FastMathFunctions/arm_sin_f32.c
	edge-impulse-sdk/CMSIS/DSP/Source/FastMathFunctions/arm_sin_q15.c
	edge-impulse-sdk/CMSIS/DSP/Source/FastMathFunctions/arm_sin_q31.c
	edge-impulse-sdk/CMSIS/DSP/Source/FastMathFunctions/arm_sqrt_q15.c
	edge-impulse-sdk/CMSIS/DSP/Source/FastMathFunctions/arm_sqrt_q31.c
	edge-impulse-sdk/CMSIS/DSP/Source/FastMathFunctions/arm_vexp_f32.c
	edge-impulse-sdk/CMSIS/DSP/Source/FastMathFunctions/arm_vlog_f32.c
	edge-impulse-sdk/CMSIS/DSP/Source/FilteringFunctions/arm_biquad_cascade_df1_32x64_init_q31.c
	edge-impulse-sdk/CMSIS/DSP/Source/FilteringFunctions/arm_biquad_cascade_df1_32x64_q31.c
	edge-impulse-sdk/CMSIS/DSP/Source/FilteringFunctions/arm_biquad_cascade_df1_f32.c
	edge-impulse-sdk/CMSIS/DSP/Source/FilteringFunctions/arm_biquad_cascade_df1_fast_q15.c
	edge-impulse-sdk/CMSIS/DSP/Source/FilteringFunctions/arm_biquad_cascade_df1_fast_q31.c
	edge-impulse-sdk/CMSIS/DSP/Source/FilteringFunctions/arm_biquad_cascade_df1_init_f32.c
	edge-impulse-sdk/CMSIS/DSP/Source/FilteringFunctions/arm_biquad_cascade_df1_init_q15.c
	edge-impulse-sdk/CMSIS/DSP/Source/FilteringFunctions/arm_biquad_cascade_df1_init_q31.c
	edge-impulse-sdk/CMSIS/DSP/Source/FilteringFunctions/arm_biquad_cascade_df1_q15.c
	edge-impulse-sdk/CMSIS/DSP/Source/FilteringFunctions/arm_biquad_cascade_df1_q31.c
	edge-impulse-sdk/CMSIS/DSP/Source/FilteringFunctions/arm_biquad_cascade_df2T_f32.c
	edge-impulse-sdk/CMSIS/DSP/Source/FilteringFunctions/arm_biquad_cascade_df2T_f64.c
	edge-impulse-sdk/CMSIS/DSP/Source/FilteringFunctions/arm_biquad_cascade_df2T_init_f32.c
	edge-impulse-sdk/CMSIS/DSP/Source/FilteringFunctions/arm_biquad_cascade_df2T_init_f64.c
	edge-impulse-sdk/CMSIS/DSP/Source/FilteringFunctions/arm_biquad_cascade_stereo_df2T_f32.c
	edge-impulse-sdk/CMSIS/DSP/Source/FilteringFunctions/arm_biquad_cascade_stereo_df2T_init_f32.c
	edge-impulse-sdk/CMSIS/DSP/Source/FilteringFunctions/arm_conv_f32.c
	edge-impulse-sdk/CMSIS/DSP/Source/FilteringFunctions/arm_conv_fast_opt_q15.c
	edge-impulse-sdk/CMSIS/DSP/Source/FilteringFunctions/arm_conv_fast_q15.c
	edge-impulse-sdk/CMSIS/DSP/Source/FilteringFunctions/arm_conv_fast_q31.c
	edge-impulse-sdk/CMSIS/DSP/Source/FilteringFunctions/arm_conv_opt_q15.c
	edge-impulse-sdk/CMSIS/DSP/Source/FilteringFunctions/arm_conv_opt_q7.c
	edge-impulse-sdk/CMSIS/DSP/Source/FilteringFunctions/arm_conv_partial_f32.c
	edge-impulse-sdk/CMSIS/DSP/Source/FilteringFunctions/arm_conv_partial_fast_opt_q15.c
	edge-impulse-sdk/CMSIS/DSP/Source/FilteringFunctions/arm_conv_partial_fast_q15.c
	edge-impulse-sdk/CMSIS/DSP/Source/FilteringFunctions/arm_conv_partial_fast_q31.c
	edge-impulse-sdk/CMSIS/DSP/Source/FilteringFunctions/arm_conv_partial_opt_q15.c
	edge-impulse-sdk/CMSIS/DSP/Source/FilteringFunctions/arm_conv_partial_opt_q7.c
	edge-impulse-sdk/CMSIS/DSP/Source/FilteringFunctions/arm_conv_partial_q15.c
	edge-impulse-sdk/CMSIS/DSP/Source/FilteringFunctions/arm_conv_partial_q31.c
	edge-impulse-sdk/CMSIS/DSP/Source/FilteringFunctions/arm_conv_partial_q7.c
	edge-impulse-sdk/CMSIS/DSP/Source/FilteringFunctions/arm_conv_q15.c
	edge-impulse-sdk/CMSIS/DSP/Source/FilteringFunctions/arm_conv_q31.c
	edge-impulse-sdk/CMSIS/DSP/Source/FilteringFunctions/arm_conv_q7.c
	edge-impulse-sdk/CMSIS/DSP/Source/FilteringFunctions/arm_correlate_f32.c
	edge-impulse-sdk/CMSIS/DSP/Source/FilteringFunctions/arm_correlate_fast_opt_q15.c
	edge-impulse-sdk/CMSIS/DSP/Source/FilteringFunctions/arm_correlate_fast_q15.c
	edge-impulse-sdk/CMSIS/DSP/Source/FilteringFunctions/arm_correlate_fast_q31.c
	edge-impulse-sdk/CMSIS/DSP/Source/FilteringFunctions/arm_correlate_opt_q15.c
	edge-impulse-sdk/CMSIS/DSP/Source/FilteringFunctions/arm_correlate_opt_q7.c
	edge-impulse-sdk/CMSIS/DSP/Source/FilteringFunctions/arm_correlate_q15.c
	edge-impulse-sdk/CMSIS/DSP/Source/FilteringFunctions/arm_correlate_q31.c
	edge-impulse-sdk/CMSIS/DSP/Source/FilteringFunctions/arm_correlate_q7.c
	edge-impulse-sdk/CMSIS/DSP/Source/FilteringFunctions/arm_fir_decimate_f32.c
	edge-impulse-sdk/CMSIS/DSP/Source/FilteringFunctions/arm_fir_decimate_fast_q15.c
	edge-impulse-sdk/CMSIS/DSP/Source/FilteringFunctions/arm_fir_decimate_fast_q31.c
	edge-impulse-sdk/CMSIS/DSP/Source/FilteringFunctions/arm_fir_decimate_init_f32.c
	edge-impulse-sdk/CMSIS/DSP/Source/FilteringFunctions/arm_fir_decimate_init_q15.c
	edge-impulse-sdk/CMSIS/DSP/Source/FilteringFunctions/arm_fir_decimate_init_q31.c
	edge-impulse-sdk/CMSIS/DSP/Source/FilteringFunctions/arm_fir_decimate_q15.c
	edge-impulse-sdk/CMSIS/DSP/Source/FilteringFunctions/arm_fir_decimate_q31.c
	edge-impulse-sdk/CMSIS/DSP/Source/FilteringFunctions/arm_fir_f32.c
	edge-impulse-sdk/CMSIS/DSP/Source/FilteringFunctions/arm_fir_fast_q15.c
	edge-impulse-sdk/CMSIS/DSP/Source/FilteringFunctions/arm_fir_fast_q31.c
	edge-impulse-sdk/CMSIS/DSP/Source/FilteringFunctions/arm_fir_init_f32.c
	edge-impulse-sdk/CMSIS/DSP/Source/FilteringFunctions/arm_fir_init_q15.c
	edge-impulse-sdk/CMSIS/DSP/Source/FilteringFunctions/arm_fir_init_q31.c
	edge-impulse-sdk/CMSIS/DSP/Source/FilteringFunctions/arm_fir_init_q7.c
	edge-impulse-sdk/CMSIS/DSP/Source/FilteringFunctions/arm_fir_interpolate_f32.c
	edge-impulse-sdk/CMSIS/DSP/Source/FilteringFunctions/arm_fir_interpolate_init_f32.c
	edge-impulse-sdk/CMSIS/DSP/Source/FilteringFunctions/arm_fir_interpolate_init_q15.c
	edge-impulse-sdk/CMSIS/DSP/Source/FilteringFunctions/arm_fir_interpolate_init_q31.c
	edge-impulse-sdk/CMSIS/DSP/Source/FilteringFunctions/arm_fir_interpolate_q15.c
	edge-impulse-sdk/CMSIS/DSP/Source/FilteringFunctions/arm_fir_interpolate_q31.c
	edge-impulse-sdk/CMSIS/DSP/Source/FilteringFunctions/arm_fir_lattice_f32.c
	edge-impulse-sdk/CMSIS/DSP/Source/FilteringFunctions/arm_fir_lattice_init_f32.c
	edge-impulse-sdk/CMSIS/DSP/Source/FilteringFunctions/arm_fir_lattice_init_q15.c
	edge-impulse-sdk/CMSIS/DSP/Source/FilteringFunctions/arm_fir_lattice_init_q31.c
	edge-impulse-sdk/CMSIS/DSP/Source/FilteringFunctions/arm_fir_lattice_q15.c
	edge-impulse-sdk/CMSIS/DSP/Source/FilteringFunctions/arm_fir_lattice_q31.c
	edge-impulse-sdk/CMSIS/DSP/Source/FilteringFunctions/arm_fir_q15.c
	edge-impulse-sdk/CMSIS/DSP/Source/FilteringFunctions/arm_fir_q31.c
	edge-impulse-sdk/CMSIS/DSP/Source/FilteringFunctions/arm_fir_q7.c
	edge-impulse-sdk/CMSIS/DSP/Source/FilteringFunctions/arm_fir_sparse_f32.c
	edge-impulse-sdk/CMSIS/DSP/Source/FilteringFunctions/arm_fir_sparse_init_f32.c
	edge-impulse-sdk/CMSIS/DSP/Source/FilteringFunctions/arm_fir_sparse_init_q15.c
	edge-impulse-sdk/CMSIS/DSP/Source/FilteringFunctions/arm_fir_sparse_init_q31.c
	edge-impulse-sdk/CMSIS/DSP/Source/FilteringFunctions/arm_fir_sparse_init_q7.c
	edge-impulse-sdk/CMSIS/DSP/Source/FilteringFunctions/arm_fir_sparse_q15.c
	edge-impulse-sdk/CMSIS/DSP/Source/FilteringFunctions/arm_fir_sparse_q31.c
	edge-impulse-sdk/CMSIS/DSP/Source/FilteringFunctions/arm_fir_sparse_q7.c
	edge-impulse-sdk/CMSIS/DSP/Source/FilteringFunctions/arm_iir_lattice_f32.c
	edge-impulse-sdk/CMSIS/DSP/Source/FilteringFunctions/arm_iir_lattice_init_f32.c
	edge-impulse-sdk/CMSIS/DSP/Source/FilteringFunctions/arm_iir_lattice_init_q15.c
	edge-impulse-sdk/CMSIS/DSP/Source/FilteringFunctions/arm_iir_lattice_init_q31.c
	edge-impulse-sdk/CMSIS/DSP/Source/FilteringFunctions/arm_iir_lattice_q15.c
	edge-impulse-sdk/CMSIS/DSP/Source/FilteringFunctions/arm_iir_lattice_q31.c
	edge-impulse-sdk/CMSIS/DSP/Source/FilteringFunctions/arm_lms_f32.c
	edge-impulse-sdk/CMSIS/DSP/Source/FilteringFunctions/arm_lms_init_f32.c
	edge-impulse-sdk/CMSIS/DSP/Source/FilteringFunctions/arm_lms_init_q15.c
	edge-impulse-sdk/CMSIS/DSP/Source/FilteringFunctions/arm_lms_init_q31.c
	edge-impulse-sdk/CMSIS/DSP/Source/FilteringFunctions/arm_lms_norm_f32.c
	edge-impulse-sdk/CMSIS/DSP/Source/FilteringFunctions/arm_lms_norm_init_f32.c
	edge-impulse-sdk/CMSIS/DSP/Source/FilteringFunctions/arm_lms_norm_init_q15.c
	edge-impulse-sdk/CMSIS/DSP/Source/FilteringFunctions/arm_lms_norm_init_q31.c
	edge-impulse-sdk/CMSIS/DSP/Source/FilteringFunctions/arm_lms_norm_q15.c
	edge-impulse-sdk/CMSIS/DSP/Source/FilteringFunctions/arm_lms_norm_q31.c
	edge-impulse-sdk/CMSIS/DSP/Source/FilteringFunctions/arm_lms_q15.c
	edge-impulse-sdk/CMSIS/DSP/Source/FilteringFunctions/arm_lms_q31.c
	edge-impulse-sdk/CMSIS/DSP/Source/MatrixFunctions/arm_mat_add_f32.c
	edge-impulse-sdk/CMSIS/DSP/Source/MatrixFunctions/arm_mat_add_q15.c
	edge-impulse-sdk/CMSIS/DSP/Source/MatrixFunctions/arm_mat_add_q31.c
	edge-impulse-sdk/CMSIS/DSP/Source/MatrixFunctions/arm_mat_cmplx_mult_f32.c
	edge-impulse-sdk/CMSIS/DSP/Source/MatrixFunctions/arm_mat_cmplx_mult_q15.c
	edge-impulse-sdk/CMSIS/DSP/Source/MatrixFunctions/arm_mat_cmplx_mult_q31.c
	edge-impulse-sdk/CMSIS/DSP/Source/MatrixFunctions/arm_mat_init_f32.c
	edge-impulse-sdk/CMSIS/DSP/Source/MatrixFunctions/arm_mat_init_q15.c
	edge-impulse-sdk/CMSIS/DSP/Source/MatrixFunctions/arm_mat_init_q31.c
	edge-impulse-sdk/CMSIS/DSP/Source/MatrixFunctions/arm_mat_inverse_f32.c
	edge-impulse-sdk/CMSIS/DSP/Source/MatrixFunctions/arm_mat_inverse_f64.c
	edge-impulse-sdk/CMSIS/DSP/Source/MatrixFunctions/arm_mat_mult_f32.c
	edge-impulse-sdk/CMSIS/DSP/Source/MatrixFunctions/arm_mat_mult_fast_q15.c
	edge-impulse-sdk/CMSIS/DSP/Source/MatrixFunctions/arm_mat_mult_fast_q31.c
	edge-impulse-sdk/CMSIS/DSP/Source/MatrixFunctions/arm_mat_mult_q15.c
	edge-impulse-sdk/CMSIS/DSP/Source/MatrixFunctions/arm_mat_mult_q31.c
	edge-impulse-sdk/CMSIS/DSP/Source/MatrixFunctions/arm_mat_scale_f32.c
	edge-impulse-sdk/CMSIS/DSP/Source/MatrixFunctions/arm_mat_scale_q15.c
	edge-impulse-sdk/CMSIS/DSP/Source/MatrixFunctions/arm_mat_scale_q31.c
	edge-impulse-sdk/CMSIS/DSP/Source/MatrixFunctions/arm_mat_sub_f32.c
	edge-impulse-sdk/CMSIS/DSP/Source/MatrixFunctions/arm_mat_sub_q15.c
	edge-impulse-sdk/CMSIS/DSP/Source/MatrixFunctions/arm_mat_sub_q31.c
	edge-impulse-sdk/CMSIS/DSP/Source/MatrixFunctions/arm_mat_trans_f32.c
	edge-impulse-sdk/CMSIS/DSP/Source/MatrixFunctions/arm_mat_trans_q15.c
	edge-impulse-sdk/CMSIS/DSP/Source/MatrixFunctions/arm_mat_trans_q31.c
	edge-impulse-sdk/CMSIS/DSP/Source/SVMFunctions/arm_svm_linear_init_f32.c
	edge-impulse-sdk/CMSIS/DSP/Source/SVMFunctions/arm_svm_linear_predict_f32.c
	edge-impulse-sdk/CMSIS/DSP/Source/SVMFunctions/arm_svm_polynomial_init_f32.c
	edge-impulse-sdk/CMSIS/DSP/Source/SVMFunctions/arm_svm_polynomial_predict_f32.c
	edge-impulse-sdk/CMSIS/DSP/Source/SVMFunctions/arm_svm_rbf_init_f32.c
	edge-impulse-sdk/CMSIS/DSP/Source/SVMFunctions/arm_svm_rbf_predict_f32.c
	edge-impulse-sdk/CMSIS/DSP/Source/SVMFunctions/arm_svm_sigmoid_init_f32.c
	edge-impulse-sdk/CMSIS/DSP/Source/SVMFunctions/arm_svm_sigmoid_predict_f32.c
	edge-impulse-sdk/CMSIS/DSP/Source/StatisticsFunctions/arm_entropy_f32.c
	edge-impulse-sdk/CMSIS/DSP/Source/StatisticsFunctions/arm_entropy_f64.c
	edge-impulse-sdk/CMSIS/DSP/Source/StatisticsFunctions/arm_kullback_leibler_f32.c
	edge-impulse-sdk/CMSIS/DSP/Source/StatisticsFunctions/arm_kullback_leibler_f64.c
	edge-impulse-sdk/CMSIS/DSP/Source/StatisticsFunctions/arm_logsumexp_dot_prod_f32.c
	edge-impulse-sdk/CMSIS/DSP/Source/StatisticsFunctions/arm_logsumexp_f32.c
	edge-impulse-sdk/CMSIS/DSP/Source/StatisticsFunctions/arm_max_f32.c
	edge-impulse-sdk/CMSIS/DSP/Source/StatisticsFunctions/arm_max_no_idx_f32.c
	edge-impulse-sdk/CMSIS/DSP/Source/StatisticsFunctions/arm_max_q15.c
	edge-impulse-sdk/CMSIS/DSP/Source/StatisticsFunctions/arm_max_q31.c
	edge-impulse-sdk/CMSIS/DSP/Source/StatisticsFunctions/arm_max_q7.c
	edge-impulse-sdk/CMSIS/DSP/Source/StatisticsFunctions/arm_mean_f32.c
	edge-impulse-sdk/CMSIS/DSP/Source/StatisticsFunctions/arm_mean_q15.c
	edge-impulse-sdk/CMSIS/DSP/Source/StatisticsFunctions/arm_mean_q31.c
	edge-impulse-sdk/CMSIS/DSP/Source/StatisticsFunctions/arm_mean_q7.c
	edge-impulse-sdk/CMSIS/DSP/Source/StatisticsFunctions/arm_min_f32.c
	edge-impulse-sdk/CMSIS/DSP/Source/StatisticsFunctions/arm_min_q15.c
	edge-impulse-sdk/CMSIS/DSP/Source/StatisticsFunctions/arm_min_q31.c
	edge-impulse-sdk/CMSIS/DSP/Source/StatisticsFunctions/arm_min_q7.c
	edge-impulse-sdk/CMSIS/DSP/Source/StatisticsFunctions/arm_power_f32.c
	edge-impulse-sdk/CMSIS/DSP/Source/StatisticsFunctions/arm_power_q15.c
	edge-impulse-sdk/CMSIS/DSP/Source/StatisticsFunctions/arm_power_q31.c
	edge-impulse-sdk/CMSIS/DSP/Source/StatisticsFunctions/arm_power_q7.c
	edge-impulse-sdk/CMSIS/DSP/Source/StatisticsFunctions/arm_rms_f32.c
	edge-impulse-sdk/CMSIS/DSP/Source/StatisticsFunctions/arm_rms_q15.c
	edge-impulse-sdk/CMSIS/DSP/Source/StatisticsFunctions/arm_rms_q31.c
	edge-impulse-sdk/CMSIS/DSP/Source/StatisticsFunctions/arm_std_f32.c
	edge-impulse-sdk/CMSIS/DSP/Source/StatisticsFunctions/arm_std_q15.c
	edge-impulse-sdk/CMSIS/DSP/Source/StatisticsFunctions/arm_std_q31.c
	edge-impulse-sdk/CMSIS/DSP/Source/StatisticsFunctions/arm_var_f32.c
	edge-impulse-sdk/CMSIS/DSP/Source/StatisticsFunctions/arm_var_q15.c
	edge-impulse-sdk/CMSIS/DSP/Source/StatisticsFunctions/arm_var_q31.c
	edge-impulse-sdk/CMSIS/DSP/Source/SupportFunctions/arm_barycenter_f32.c
	edge-impulse-sdk/CMSIS/DSP/Source/SupportFunctions/arm_bitonic_sort_f32.c
	edge-impulse-sdk/CMSIS/DSP/Source/SupportFunctions/arm_bubble_sort_f32.c
	edge-impulse-sdk/CMSIS/DSP/Source/SupportFunctions/arm_copy_f32.c
	edge-impulse-sdk/CMSIS/DSP/Source/SupportFunctions/arm_copy_q15.c
	edge-impulse-sdk/CMSIS/DSP/Source/SupportFunctions/arm_copy_q31.c
	edge-impulse-sdk/CMSIS/DSP/Source/SupportFunctions/arm_copy_q7.c
	edge-impulse-sdk/CMSIS/DSP/Source/SupportFunctions/arm_fill_f32.c
	edge-impulse-sdk/CMSIS/DSP/Source/SupportFunctions/arm_fill_q15.c
	edge-impulse-sdk/CMSIS/DSP/Source/SupportFunctions/arm_fill_q31.c
	edge-impulse-sdk/CMSIS/DSP/Source/SupportFunctions/arm_fill_q7.c
	edge-impulse-sdk/CMSIS/DSP/Source/SupportFunctions/arm_float_to_q15.c
	edge-impulse-sdk/CMSIS/DSP/Source/SupportFunctions/arm_float_to_q31.c
	edge-impulse-sdk/CMSIS/DSP/Source/SupportFunctions/arm_float_to_q7.c
	edge-impulse-sdk/CMSIS/DSP/Source/SupportFunctions/arm_heap_sort_f32.c
	edge-impulse-sdk/CMSIS/DSP/Source/SupportFunctions/arm_insertion_sort_f32.c
	edge-impulse-sdk/CMSIS/DSP/Source/SupportFunctions/arm_merge_sort_f32.c
	edge-impulse-sdk/CMSIS/DSP/Source/SupportFunctions/arm_merge_sort_init_f32.c
	edge-impulse-sdk/CMSIS/DSP/Source/SupportFunctions/arm_q15_to_float.c
	edge-impulse-sdk/CMSIS/DSP/Source/SupportFunctions/arm_q15_to_q31.c
	edge-impulse-sdk/CMSIS/DSP/Source/SupportFunctions/arm_q15_to_q7.c
	edge-impulse-sdk/CMSIS/DSP/Source/SupportFunctions/arm_q31_to_float.c
	edge-impulse-sdk/CMSIS/DSP/Source/SupportFunctions/arm_q31_to_q15.c
	edge-impulse-sdk/CMSIS/DSP/Source/SupportFunctions/arm_q31_to_q7.c
	edge-impulse-sdk/CMSIS/DSP/Source/SupportFunctions/arm_q7_to_float.c
	edge-impulse-sdk/CMSIS/DSP/Source/SupportFunctions/arm_q7_to_q15.c
	edge-impulse-sdk/CMSIS/DSP/Source/SupportFunctions/arm_q7_to_q31.c
	edge-impulse-sdk/CMSIS/DSP/Source/SupportFunctions/arm_quick_sort_f32.c
	edge-impulse-sdk/CMSIS/DSP/Source/SupportFunctions/arm_selection_sort_f32.c
	edge-impulse-sdk/CMSIS/DSP/Source/SupportFunctions/arm_sort_f32.c
	edge-impulse-sdk/CMSIS/DSP/Source/SupportFunctions/arm_sort_init_f32.c
	edge-impulse-sdk/CMSIS/DSP/Source/SupportFunctions/arm_spline_interp_f32.c
	edge-impulse-sdk/CMSIS/DSP/Source/SupportFunctions/arm_spline_interp_init_f32.c
	edge-impulse-sdk/CMSIS/DSP/Source/SupportFunctions/arm_weighted_sum_f32.c
	edge-impulse-sdk/CMSIS/DSP/Source/TransformFunctions/TransformFunctionsF16.c
	edge-impulse-sdk/CMSIS/DSP/Source/TransformFunctions/arm_bitreversal.c
	edge-impulse-sdk/CMSIS/DSP/Source/TransformFunctions/arm_bitreversal2.c
	edge-impulse-sdk/CMSIS/DSP/Source/TransformFunctions/arm_cfft_f16.c
	edge-impulse-sdk/CMSIS/DSP/Source/TransformFunctions/arm_cfft_f32.c
	edge-impulse-sdk/CMSIS/DSP/Source/TransformFunctions/arm_cfft_f64.c
	edge-impulse-sdk/CMSIS/DSP/Source/TransformFunctions/arm_cfft_init_f16.c
	edge-impulse-sdk/CMSIS/DSP/Source/TransformFunctions/arm_cfft_init_f32.c
	edge-impulse-sdk/CMSIS/DSP/Source/TransformFunctions/arm_cfft_init_f64.c
	edge-impulse-sdk/CMSIS/DSP/Source/TransformFunctions/arm_cfft_init_q15.c
	edge-impulse-sdk/CMSIS/DSP/Source/TransformFunctions/arm_cfft_init_q31.c
	edge-impulse-sdk/CMSIS/DSP/Source/TransformFunctions/arm_cfft_q15.c
	edge-impulse-sdk/CMSIS/DSP/Source/TransformFunctions/arm_cfft_q31.c
	edge-impulse-sdk/CMSIS/DSP/Source/TransformFunctions/arm_cfft_radix2_f16.c
	edge-impulse-sdk/CMSIS/DSP/Source/TransformFunctions/arm_cfft_radix2_f32.c
	edge-impulse-sdk/CMSIS/DSP/Source/TransformFunctions/arm_cfft_radix2_init_f32.c
	edge-impulse-sdk/CMSIS/DSP/Source/TransformFunctions/arm_cfft_radix2_init_q15.c
	edge-impulse-sdk/CMSIS/DSP/Source/TransformFunctions/arm_cfft_radix2_init_q31.c
	edge-impulse-sdk/CMSIS/DSP/Source/TransformFunctions/arm_cfft_radix2_q15.c
	edge-impulse-sdk/CMSIS/DSP/Source/TransformFunctions/arm_cfft_radix2_q31.c
	edge-impulse-sdk/CMSIS/DSP/Source/TransformFunctions/arm_cfft_radix4_f16.c
	edge-impulse-sdk/CMSIS/DSP/Source/TransformFunctions/arm_cfft_radix4_f32.c
	edge-impulse-sdk/CMSIS/DSP/Source/TransformFunctions/arm_cfft_radix4_init_f32.c
	edge-impulse-sdk/CMSIS/DSP/Source/TransformFunctions/arm_cfft_radix4_init_q15.c
	edge-impulse-sdk/CMSIS/DSP/Source/TransformFunctions/arm_cfft_radix4_init_q31.c
	edge-impulse-sdk/CMSIS/DSP/Source/TransformFunctions/arm_cfft_radix4_q15.c
	edge-impulse-sdk/CMSIS/DSP/Source/TransformFunctions/arm_cfft_radix4_q31.c
	edge-impulse-sdk/CMSIS/DSP/Source/TransformFunctions/arm_cfft_radix8_f32.c
	edge-impulse-sdk/CMSIS/DSP/Source/TransformFunctions/arm_dct4_f32.c
	edge-impulse-sdk/CMSIS/DSP/Source/TransformFunctions/arm_dct4_init_f32.c
	edge-impulse-sdk/CMSIS/DSP/Source/TransformFunctions/arm_dct4_init_q15.c
	edge-impulse-sdk/CMSIS/DSP/Source/TransformFunctions/arm_dct4_init_q31.c
	edge-impulse-sdk/CMSIS/DSP/Source/TransformFunctions/arm_dct4_q15.c
	edge-impulse-sdk/CMSIS/DSP/Source/TransformFunctions/arm_dct4_q31.c
	edge-impulse-sdk/CMSIS/DSP/Source/TransformFunctions/arm_rfft_f32.c
	edge-impulse-sdk/CMSIS/DSP/Source/TransformFunctions/arm_rfft_fast_f32.c
	edge-impulse-sdk/CMSIS/DSP/Source/TransformFunctions/arm_rfft_fast_f64.c
	edge-impulse-sdk/CMSIS/DSP/Source/TransformFunctions/arm_rfft_fast_init_f32.c
	edge-impulse-sdk/CMSIS/DSP/Source/TransformFunctions/arm_rfft_fast_init_f64.c
	edge-impulse-sdk/CMSIS/DSP/Source/TransformFunctions/arm_rfft_init_f32.c
	edge-impulse-sdk/CMSIS/DSP/Source/TransformFunctions/arm_rfft_init_q15.c
	edge-impulse-sdk/CMSIS/DSP/Source/TransformFunctions/arm_rfft_init_q31.c
	edge-impulse-sdk/CMSIS/DSP/Source/TransformFunctions/arm_rfft_q15.c
	edge-impulse-sdk/CMSIS/DSP/Source/TransformFunctions/arm_rfft_q31.c
	edge-impulse-sdk/CMSIS/NN/Include/arm_nn_tables.h
	edge-impulse-sdk/CMSIS/NN/Include/arm_nn_types.h
	edge-impulse-sdk/CMSIS/NN/Include/arm_nnfunctions.h
	edge-impulse-sdk/CMSIS/NN/Include/arm_nnsupportfunctions.h
	edge-impulse-sdk/CMSIS/NN/Source/ActivationFunctions/arm_nn_activations_q15.c
	edge-impulse-sdk/CMSIS/NN/Source/ActivationFunctions/arm_nn_activations_q7.c
	edge-impulse-sdk/CMSIS/NN/Source/ActivationFunctions/arm_relu6_s8.c
	edge-impulse-sdk/CMSIS/NN/Source/ActivationFunctions/arm_relu_q15.c
	edge-impulse-sdk/CMSIS/NN/Source/ActivationFunctions/arm_relu_q7.c
	edge-impulse-sdk/CMSIS/NN/Source/BasicMathFunctions/arm_elementwise_add_s8.c
	edge-impulse-sdk/CMSIS/NN/Source/BasicMathFunctions/arm_elementwise_mul_s8.c
	edge-impulse-sdk/CMSIS/NN/Source/ConcatenationFunctions/arm_concatenation_s8_w.c
	edge-impulse-sdk/CMSIS/NN/Source/ConcatenationFunctions/arm_concatenation_s8_x.c
	edge-impulse-sdk/CMSIS/NN/Source/ConcatenationFunctions/arm_concatenation_s8_y.c
	edge-impulse-sdk/CMSIS/NN/Source/ConcatenationFunctions/arm_concatenation_s8_z.c
	edge-impulse-sdk/CMSIS/NN/Source/ConvolutionFunctions/arm_convolve_1_x_n_s8.c
	edge-impulse-sdk/CMSIS/NN/Source/ConvolutionFunctions/arm_convolve_1x1_HWC_q7_fast_nonsquare.c
	edge-impulse-sdk/CMSIS/NN/Source/ConvolutionFunctions/arm_convolve_1x1_s8_fast.c
	edge-impulse-sdk/CMSIS/NN/Source/ConvolutionFunctions/arm_convolve_HWC_q15_basic.c
	edge-impulse-sdk/CMSIS/NN/Source/ConvolutionFunctions/arm_convolve_HWC_q15_fast.c
	edge-impulse-sdk/CMSIS/NN/Source/ConvolutionFunctions/arm_convolve_HWC_q15_fast_nonsquare.c
	edge-impulse-sdk/CMSIS/NN/Source/ConvolutionFunctions/arm_convolve_HWC_q7_RGB.c
	edge-impulse-sdk/CMSIS/NN/Source/ConvolutionFunctions/arm_convolve_HWC_q7_basic.c
	edge-impulse-sdk/CMSIS/NN/Source/ConvolutionFunctions/arm_convolve_HWC_q7_basic_nonsquare.c
	edge-impulse-sdk/CMSIS/NN/Source/ConvolutionFunctions/arm_convolve_HWC_q7_fast.c
	edge-impulse-sdk/CMSIS/NN/Source/ConvolutionFunctions/arm_convolve_HWC_q7_fast_nonsquare.c
	edge-impulse-sdk/CMSIS/NN/Source/ConvolutionFunctions/arm_convolve_s8.c
	edge-impulse-sdk/CMSIS/NN/Source/ConvolutionFunctions/arm_convolve_wrapper_s8.c
	edge-impulse-sdk/CMSIS/NN/Source/ConvolutionFunctions/arm_depthwise_conv_3x3_s8.c
	edge-impulse-sdk/CMSIS/NN/Source/ConvolutionFunctions/arm_depthwise_conv_s8.c
	edge-impulse-sdk/CMSIS/NN/Source/ConvolutionFunctions/arm_depthwise_conv_s8_opt.c
	edge-impulse-sdk/CMSIS/NN/Source/ConvolutionFunctions/arm_depthwise_conv_u8_basic_ver1.c
	edge-impulse-sdk/CMSIS/NN/Source/ConvolutionFunctions/arm_depthwise_separable_conv_HWC_q7.c
	edge-impulse-sdk/CMSIS/NN/Source/ConvolutionFunctions/arm_depthwise_separable_conv_HWC_q7_nonsquare.c
	edge-impulse-sdk/CMSIS/NN/Source/ConvolutionFunctions/arm_nn_depthwise_conv_s8_core.c
	edge-impulse-sdk/CMSIS/NN/Source/ConvolutionFunctions/arm_nn_mat_mult_kernel_q7_q15.c
	edge-impulse-sdk/CMSIS/NN/Source/ConvolutionFunctions/arm_nn_mat_mult_kernel_q7_q15_reordered.c
	edge-impulse-sdk/CMSIS/NN/Source/ConvolutionFunctions/arm_nn_mat_mult_kernel_s8_s16.c
	edge-impulse-sdk/CMSIS/NN/Source/ConvolutionFunctions/arm_nn_mat_mult_kernel_s8_s16_reordered.c
	edge-impulse-sdk/CMSIS/NN/Source/ConvolutionFunctions/arm_nn_mat_mult_s8.c
	edge-impulse-sdk/CMSIS/NN/Source/FullyConnectedFunctions/arm_fully_connected_mat_q7_vec_q15.c
	edge-impulse-sdk/CMSIS/NN/Source/FullyConnectedFunctions/arm_fully_connected_mat_q7_vec_q15_opt.c
	edge-impulse-sdk/CMSIS/NN/Source/FullyConnectedFunctions/arm_fully_connected_q15.c
	edge-impulse-sdk/CMSIS/NN/Source/FullyConnectedFunctions/arm_fully_connected_q15_opt.c
	edge-impulse-sdk/CMSIS/NN/Source/FullyConnectedFunctions/arm_fully_connected_q7.c
	edge-impulse-sdk/CMSIS/NN/Source/FullyConnectedFunctions/arm_fully_connected_q7_opt.c
	edge-impulse-sdk/CMSIS/NN/Source/FullyConnectedFunctions/arm_fully_connected_s8.c
	edge-impulse-sdk/CMSIS/NN/Source/NNSupportFunctions/arm_nn_accumulate_q7_to_q15.c
	edge-impulse-sdk/CMSIS/NN/Source/NNSupportFunctions/arm_nn_add_q7.c
	edge-impulse-sdk/CMSIS/NN/Source/NNSupportFunctions/arm_nn_depthwise_conv_nt_t_padded_s8.c
	edge-impulse-sdk/CMSIS/NN/Source/NNSupportFunctions/arm_nn_depthwise_conv_nt_t_s8.c
	edge-impulse-sdk/CMSIS/NN/Source/NNSupportFunctions/arm_nn_mat_mul_core_1x_s8.c
	edge-impulse-sdk/CMSIS/NN/Source/NNSupportFunctions/arm_nn_mat_mul_core_4x_s8.c
	edge-impulse-sdk/CMSIS/NN/Source/NNSupportFunctions/arm_nn_mat_mult_nt_t_s8.c
	edge-impulse-sdk/CMSIS/NN/Source/NNSupportFunctions/arm_nn_mult_q15.c
	edge-impulse-sdk/CMSIS/NN/Source/NNSupportFunctions/arm_nn_mult_q7.c
	edge-impulse-sdk/CMSIS/NN/Source/NNSupportFunctions/arm_nn_vec_mat_mult_t_s8.c
	edge-impulse-sdk/CMSIS/NN/Source/NNSupportFunctions/arm_nntables.c
	edge-impulse-sdk/CMSIS/NN/Source/NNSupportFunctions/arm_q7_to_q15_no_shift.c
	edge-impulse-sdk/CMSIS/NN/Source/NNSupportFunctions/arm_q7_to_q15_reordered_no_shift.c
	edge-impulse-sdk/CMSIS/NN/Source/NNSupportFunctions/arm_q7_to_q15_reordered_with_offset.c
	edge-impulse-sdk/CMSIS/NN/Source/NNSupportFunctions/arm_q7_to_q15_with_offset.c
	edge-impulse-sdk/CMSIS/NN/Source/PoolingFunctions/arm_avgpool_s8.c
	edge-impulse-sdk/CMSIS/NN/Source/PoolingFunctions/arm_max_pool_s8.c
	edge-impulse-sdk/CMSIS/NN/Source/PoolingFunctions/arm_max_pool_s8_opt.c
	edge-impulse-sdk/CMSIS/NN/Source/PoolingFunctions/arm_pool_q7_HWC.c
	edge-impulse-sdk/CMSIS/NN/Source/ReshapeFunctions/arm_reshape_s8.c
	edge-impulse-sdk/CMSIS/NN/Source/SoftmaxFunctions/arm_softmax_q15.c
	edge-impulse-sdk/CMSIS/NN/Source/SoftmaxFunctions/arm_softmax_q7.c
	edge-impulse-sdk/CMSIS/NN/Source/SoftmaxFunctions/arm_softmax_s8.c
	edge-impulse-sdk/CMSIS/NN/Source/SoftmaxFunctions/arm_softmax_u8.c
	edge-impulse-sdk/CMSIS/NN/Source/SoftmaxFunctions/arm_softmax_with_batch_q7.c
	edge-impulse-sdk/anomaly/anomaly.h
	edge-impulse-sdk/classifier/ei_aligned_malloc.h
	edge-impulse-sdk/classifier/ei_classifier_config.h
	edge-impulse-sdk/classifier/ei_classifier_types.h
	edge-impulse-sdk/classifier/ei_model_types.h
	edge-impulse-sdk/classifier/ei_run_classifier.h
	edge-impulse-sdk/classifier/ei_run_dsp.h
	edge-impulse-sdk/dsp/config.hpp
	edge-impulse-sdk/dsp/dct/fast-dct-fft.cpp
	edge-impulse-sdk/dsp/dct/fast-dct-fft.h
	edge-impulse-sdk/dsp/kissfft/_kiss_fft_guts.h
	edge-impulse-sdk/dsp/kissfft/kiss_fft.cpp
	edge-impulse-sdk/dsp/kissfft/kiss_fft.h
	edge-impulse-sdk/dsp/kissfft/kiss_fftr.cpp
	edge-impulse-sdk/dsp/kissfft/kiss_fftr.h
	edge-impulse-sdk/dsp/kissfft/kissfft.h
	edge-impulse-sdk/dsp/kissfft/kissfft.hh
	edge-impulse-sdk/dsp/kissfft/kissfft_i32.hh
	edge-impulse-sdk/dsp/memory.cpp
	edge-impulse-sdk/dsp/memory.hpp
	edge-impulse-sdk/dsp/numpy.hpp
	edge-impulse-sdk/dsp/numpy_types.h
	edge-impulse-sdk/dsp/returntypes.hpp
	edge-impulse-sdk/dsp/spectral/feature.hpp
	edge-impulse-sdk/dsp/spectral/filters.hpp
	edge-impulse-sdk/dsp/spectral/processing.hpp
	edge-impulse-sdk/dsp/spectral/spectral.hpp
	edge-impulse-sdk/dsp/speechpy/feature.hpp
	edge-impulse-sdk/dsp/speechpy/functions.hpp
	edge-impulse-sdk/dsp/speechpy/processing.hpp
	edge-impulse-sdk/dsp/speechpy/speechpy.hpp
	edge-impulse-sdk/porting/ei_classifier_porting.h
	# edge-impulse-sdk/porting/zephyr/debug_log.cpp
	# edge-impulse-sdk/porting/zephyr/ei_classifier_porting.cpp
	edge-impulse-sdk/tensorflow/core/public/version.h
	edge-impulse-sdk/tensorflow/lite/c/builtin_op_data.h
	edge-impulse-sdk/tensorflow/lite/c/common.c
	edge-impulse-sdk/tensorflow/lite/c/common.h
	edge-impulse-sdk/tensorflow/lite/core/api/error_reporter.cc
	edge-impulse-sdk/tensorflow/lite/core/api/error_reporter.h
	edge-impulse-sdk/tensorflow/lite/core/api/flatbuffer_conversions.cc
	edge-impulse-sdk/tensorflow/lite/core/api/flatbuffer_conversions.h
	edge-impulse-sdk/tensorflow/lite/core/api/op_resolver.cc
	edge-impulse-sdk/tensorflow/lite/core/api/op_resolver.h
	edge-impulse-sdk/tensorflow/lite/core/api/profiler.h
	edge-impulse-sdk/tensorflow/lite/core/api/tensor_utils.cc
	edge-impulse-sdk/tensorflow/lite/core/api/tensor_utils.h
	edge-impulse-sdk/tensorflow/lite/kernels/internal/common.h
	edge-impulse-sdk/tensorflow/lite/kernels/internal/compatibility.h
	edge-impulse-sdk/tensorflow/lite/kernels/internal/cppmath.h
	edge-impulse-sdk/tensorflow/lite/kernels/internal/max.h
	edge-impulse-sdk/tensorflow/lite/kernels/internal/min.h
	edge-impulse-sdk/tensorflow/lite/kernels/internal/optimized/neon_check.h
	edge-impulse-sdk/tensorflow/lite/kernels/internal/quantization_util.cc
	edge-impulse-sdk/tensorflow/lite/kernels/internal/quantization_util.h
	edge-impulse-sdk/tensorflow/lite/kernels/internal/reference/add.h
	edge-impulse-sdk/tensorflow/lite/kernels/internal/reference/arg_min_max.h
	edge-impulse-sdk/tensorflow/lite/kernels/internal/reference/binary_function.h
	edge-impulse-sdk/tensorflow/lite/kernels/internal/reference/ceil.h
	edge-impulse-sdk/tensorflow/lite/kernels/internal/reference/comparisons.h
	edge-impulse-sdk/tensorflow/lite/kernels/internal/reference/concatenation.h
	edge-impulse-sdk/tensorflow/lite/kernels/internal/reference/conv.h
	edge-impulse-sdk/tensorflow/lite/kernels/internal/reference/depthwiseconv_float.h
	edge-impulse-sdk/tensorflow/lite/kernels/internal/reference/depthwiseconv_uint8.h
	edge-impulse-sdk/tensorflow/lite/kernels/internal/reference/dequantize.h
	edge-impulse-sdk/tensorflow/lite/kernels/internal/reference/floor.h
	edge-impulse-sdk/tensorflow/lite/kernels/internal/reference/fully_connected.h
	edge-impulse-sdk/tensorflow/lite/kernels/internal/reference/integer_ops/add.h
	edge-impulse-sdk/tensorflow/lite/kernels/internal/reference/integer_ops/conv.h
	edge-impulse-sdk/tensorflow/lite/kernels/internal/reference/integer_ops/depthwise_conv.h
	edge-impulse-sdk/tensorflow/lite/kernels/internal/reference/integer_ops/fully_connected.h
	edge-impulse-sdk/tensorflow/lite/kernels/internal/reference/integer_ops/l2normalization.h
	edge-impulse-sdk/tensorflow/lite/kernels/internal/reference/integer_ops/logistic.h
	edge-impulse-sdk/tensorflow/lite/kernels/internal/reference/integer_ops/mul.h
	edge-impulse-sdk/tensorflow/lite/kernels/internal/reference/integer_ops/pooling.h
	edge-impulse-sdk/tensorflow/lite/kernels/internal/reference/integer_ops/tanh.h
	edge-impulse-sdk/tensorflow/lite/kernels/internal/reference/l2normalization.h
	edge-impulse-sdk/tensorflow/lite/kernels/internal/reference/logistic.h
	edge-impulse-sdk/tensorflow/lite/kernels/internal/reference/maximum_minimum.h
	edge-impulse-sdk/tensorflow/lite/kernels/internal/reference/mul.h
	edge-impulse-sdk/tensorflow/lite/kernels/internal/reference/neg.h
	edge-impulse-sdk/tensorflow/lite/kernels/internal/reference/pad.h
	edge-impulse-sdk/tensorflow/lite/kernels/internal/reference/pooling.h
	edge-impulse-sdk/tensorflow/lite/kernels/internal/reference/prelu.h
	edge-impulse-sdk/tensorflow/lite/kernels/internal/reference/process_broadcast_shapes.h
	edge-impulse-sdk/tensorflow/lite/kernels/internal/reference/quantize.h
	edge-impulse-sdk/tensorflow/lite/kernels/internal/reference/reduce.h
	edge-impulse-sdk/tensorflow/lite/kernels/internal/reference/requantize.h
	edge-impulse-sdk/tensorflow/lite/kernels/internal/reference/resize_nearest_neighbor.h
	edge-impulse-sdk/tensorflow/lite/kernels/internal/reference/round.h
	edge-impulse-sdk/tensorflow/lite/kernels/internal/reference/softmax.h
	edge-impulse-sdk/tensorflow/lite/kernels/internal/reference/strided_slice.h
	edge-impulse-sdk/tensorflow/lite/kernels/internal/reference/sub.h
	edge-impulse-sdk/tensorflow/lite/kernels/internal/reference/tanh.h
	edge-impulse-sdk/tensorflow/lite/kernels/internal/strided_slice_logic.h
	edge-impulse-sdk/tensorflow/lite/kernels/internal/tensor.h
	edge-impulse-sdk/tensorflow/lite/kernels/internal/tensor_ctypes.h
	edge-impulse-sdk/tensorflow/lite/kernels/internal/types.h
	edge-impulse-sdk/tensorflow/lite/kernels/kernel_util.h
	edge-impulse-sdk/tensorflow/lite/kernels/kernel_util_lite.cc
	edge-impulse-sdk/tensorflow/lite/kernels/op_macros.h
	edge-impulse-sdk/tensorflow/lite/kernels/padding.h
	edge-impulse-sdk/tensorflow/lite/micro/all_ops_resolver.cc
	edge-impulse-sdk/tensorflow/lite/micro/all_ops_resolver.h
	edge-impulse-sdk/tensorflow/lite/micro/compatibility.h
	edge-impulse-sdk/tensorflow/lite/micro/debug_log.h
	edge-impulse-sdk/tensorflow/lite/micro/kernels/activation_utils.h
	edge-impulse-sdk/tensorflow/lite/micro/kernels/activations.cc
	edge-impulse-sdk/tensorflow/lite/micro/kernels/add.cc
	edge-impulse-sdk/tensorflow/lite/micro/kernels/arg_min_max.cc
	edge-impulse-sdk/tensorflow/lite/micro/kernels/ceil.cc
	edge-impulse-sdk/tensorflow/lite/micro/kernels/circular_buffer.cc
	edge-impulse-sdk/tensorflow/lite/micro/kernels/comparisons.cc
	edge-impulse-sdk/tensorflow/lite/micro/kernels/concatenation.cc
	edge-impulse-sdk/tensorflow/lite/micro/kernels/conv.cc
	edge-impulse-sdk/tensorflow/lite/micro/kernels/depthwise_conv.cc
	edge-impulse-sdk/tensorflow/lite/micro/kernels/dequantize.cc
	edge-impulse-sdk/tensorflow/lite/micro/kernels/elementwise.cc
	edge-impulse-sdk/tensorflow/lite/micro/kernels/ethosu.cc
	edge-impulse-sdk/tensorflow/lite/micro/kernels/floor.cc
	edge-impulse-sdk/tensorflow/lite/micro/kernels/fully_connected.cc
	edge-impulse-sdk/tensorflow/lite/micro/kernels/l2norm.cc
	edge-impulse-sdk/tensorflow/lite/micro/kernels/logical.cc
	edge-impulse-sdk/tensorflow/lite/micro/kernels/logistic.cc
	edge-impulse-sdk/tensorflow/lite/micro/kernels/maximum_minimum.cc
	edge-impulse-sdk/tensorflow/lite/micro/kernels/micro_ops.h
	edge-impulse-sdk/tensorflow/lite/micro/kernels/micro_utils.h
	edge-impulse-sdk/tensorflow/lite/micro/kernels/mul.cc
	edge-impulse-sdk/tensorflow/lite/micro/kernels/neg.cc
	edge-impulse-sdk/tensorflow/lite/micro/kernels/pack.cc
	edge-impulse-sdk/tensorflow/lite/micro/kernels/pad.cc
	edge-impulse-sdk/tensorflow/lite/micro/kernels/pooling.cc
	edge-impulse-sdk/tensorflow/lite/micro/kernels/prelu.cc
	edge-impulse-sdk/tensorflow/lite/micro/kernels/quantize.cc
	edge-impulse-sdk/tensorflow/lite/micro/kernels/reduce.cc
	edge-impulse-sdk/tensorflow/lite/micro/kernels/reshape.cc
	edge-impulse-sdk/tensorflow/lite/micro/kernels/resize_nearest_neighbor.cc
	edge-impulse-sdk/tensorflow/lite/micro/kernels/round.cc
	edge-impulse-sdk/tensorflow/lite/micro/kernels/softmax.cc
	edge-impulse-sdk/tensorflow/lite/micro/kernels/split.cc
	edge-impulse-sdk/tensorflow/lite/micro/kernels/strided_slice.cc
	edge-impulse-sdk/tensorflow/lite/micro/kernels/sub.cc
	edge-impulse-sdk/tensorflow/lite/micro/kernels/svdf.cc
	edge-impulse-sdk/tensorflow/lite/micro/kernels/tanh.cc
	edge-impulse-sdk/tensorflow/lite/micro/kernels/unpack.cc
	edge-impulse-sdk/tensorflow/lite/micro/memory_helpers.cc
	edge-impulse-sdk/tensorflow/lite/micro/memory_helpers.h
	edge-impulse-sdk/tensorflow/lite/micro/memory_planner/greedy_memory_planner.cc
	edge-impulse-sdk/tensorflow/lite/micro/memory_planner/greedy_memory_planner.h
	edge-impulse-sdk/tensorflow/lite/micro/memory_planner/linear_memory_planner.cc
	edge-impulse-sdk/tensorflow/lite/micro/memory_planner/linear_memory_planner.h
	edge-impulse-sdk/tensorflow/lite/micro/memory_planner/memory_planner.h
	edge-impulse-sdk/tensorflow/lite/micro/micro_allocator.cc
	edge-impulse-sdk/tensorflow/lite/micro/micro_allocator.h
	edge-impulse-sdk/tensorflow/lite/micro/micro_error_reporter.cc
	edge-impulse-sdk/tensorflow/lite/micro/micro_error_reporter.h
	edge-impulse-sdk/tensorflow/lite/micro/micro_interpreter.cc
	edge-impulse-sdk/tensorflow/lite/micro/micro_interpreter.h
	edge-impulse-sdk/tensorflow/lite/micro/micro_mutable_op_resolver.h
	edge-impulse-sdk/tensorflow/lite/micro/micro_op_resolver.h
	edge-impulse-sdk/tensorflow/lite/micro/micro_optional_debug_tools.cc
	edge-impulse-sdk/tensorflow/lite/micro/micro_optional_debug_tools.h
	edge-impulse-sdk/tensorflow/lite/micro/micro_profiler.cc
	edge-impulse-sdk/tensorflow/lite/micro/micro_profiler.h
	edge-impulse-sdk/tensorflow/lite/micro/micro_string.cc
	edge-impulse-sdk/tensorflow/lite/micro/micro_string.h
	edge-impulse-sdk/tensorflow/lite/micro/micro_time.cc
	edge-impulse-sdk/tensorflow/lite/micro/micro_time.h
	edge-impulse-sdk/tensorflow/lite/micro/micro_utils.cc
	edge-impulse-sdk/tensorflow/lite/micro/micro_utils.h
	edge-impulse-sdk/tensorflow/lite/micro/recording_micro_allocator.cc
	edge-impulse-sdk/tensorflow/lite/micro/recording_micro_allocator.h
	edge-impulse-sdk/tensorflow/lite/micro/recording_micro_interpreter.h
	edge-impulse-sdk/tensorflow/lite/micro/recording_simple_memory_allocator.cc
	edge-impulse-sdk/tensorflow/lite/micro/recording_simple_memory_allocator.h
	edge-impulse-sdk/tensorflow/lite/micro/simple_memory_allocator.cc
	edge-impulse-sdk/tensorflow/lite/micro/simple_memory_allocator.h
	# edge-impulse-sdk/tensorflow/lite/micro/test_helpers.cc
	# edge-impulse-sdk/tensorflow/lite/micro/test_helpers.h
	# edge-impulse-sdk/tensorflow/lite/micro/testing/micro_test.h
	# edge-impulse-sdk/tensorflow/lite/micro/testing/test_conv_model.cc
	# edge-impulse-sdk/tensorflow/lite/micro/testing/test_conv_model.h
	# edge-impulse-sdk/tensorflow/lite/micro/testing/test_utils.cc
	# edge-impulse-sdk/tensorflow/lite/micro/testing/test_utils.h
	edge-impulse-sdk/tensorflow/lite/schema/schema_generated.h
	edge-impulse-sdk/tensorflow/lite/string_type.h
	edge-impulse-sdk/tensorflow/lite/string_util.h
	edge-impulse-sdk/tensorflow/lite/type_to_tflitetype.h
	edge-impulse-sdk/tensorflow/lite/version.h
	edge-impulse-sdk/third_party/flatbuffers/include/flatbuffers/base.h
	edge-impulse-sdk/third_party/flatbuffers/include/flatbuffers/flatbuffers.h
	edge-impulse-sdk/third_party/flatbuffers/include/flatbuffers/stl_emulation.h
	edge-impulse-sdk/third_party/gemmlowp/fixedpoint/fixedpoint.h
	edge-impulse-sdk/third_party/gemmlowp/fixedpoint/fixedpoint_sse.h
	edge-impulse-sdk/third_party/gemmlowp/internal/detect_platform.h
	edge-impulse-sdk/third_party/ruy/ruy/profiler/instrumentation.h
	# edge-impulse-sdk/utensor/src/uTensor.h
	# edge-impulse-sdk/utensor/src/uTensor/core/context.cpp
	# edge-impulse-sdk/utensor/src/uTensor/core/context.hpp
	# edge-impulse-sdk/utensor/src/uTensor/core/sdtensor.hpp
	# edge-impulse-sdk/utensor/src/uTensor/core/tensor.cpp
	# edge-impulse-sdk/utensor/src/uTensor/core/tensor.hpp
	# edge-impulse-sdk/utensor/src/uTensor/core/uTensorBase.cpp
	# edge-impulse-sdk/utensor/src/uTensor/core/uTensorBase.hpp
	# edge-impulse-sdk/utensor/src/uTensor/core/vm.cpp
	# edge-impulse-sdk/utensor/src/uTensor/core/vm.hpp
	# edge-impulse-sdk/utensor/src/uTensor/loaders/tensorIdxImporter.cpp
	# edge-impulse-sdk/utensor/src/uTensor/loaders/tensorIdxImporter.hpp
	# edge-impulse-sdk/utensor/src/uTensor/ops/ArrayOps.hpp
	# edge-impulse-sdk/utensor/src/uTensor/ops/MathOps.cpp
	# edge-impulse-sdk/utensor/src/uTensor/ops/MathOps.hpp
	# edge-impulse-sdk/utensor/src/uTensor/ops/MatrixOps.hpp
	# edge-impulse-sdk/utensor/src/uTensor/ops/NnOps.hpp
	# edge-impulse-sdk/utensor/src/uTensor/ops/cmsis_ops/CmsisConvolution.hpp
	# edge-impulse-sdk/utensor/src/uTensor/ops/cmsis_ops/CmsisPoolingOps.hpp
	# edge-impulse-sdk/utensor/src/uTensor/ops/cmsis_ops/FullyConnectedOps.hpp
	# edge-impulse-sdk/utensor/src/uTensor/ops/cmsis_ops/activationOps.hpp
	# edge-impulse-sdk/utensor/src/uTensor/ops/cmsis_ops/softmax.hpp
	# edge-impulse-sdk/utensor/src/uTensor/util/math_utils.hpp
	# edge-impulse-sdk/utensor/src/uTensor/util/quantization_utils.cpp
	# edge-impulse-sdk/utensor/src/uTensor/util/quantization_utils.hpp
	# edge-impulse-sdk/utensor/src/uTensor/util/uTensor_util.cpp
	# edge-impulse-sdk/utensor/src/uTensor/util/uTensor_util.hpp
	# edge-impulse-sdk/utensor/src/uTensor/util/utensor_string.hpp
	model-parameters/dsp_blocks.h
	model-parameters/model_metadata.h
	tflite-model/trained_model_compiled.cpp
	tflite-model/trained_model_compiled.h
	)

# SET_TARGET_PROPERTIES(example-standalone-inferencing-nrf52-zephyr PROPERTIES ENABLE_EXPORTS 1)
# #add syslibs dependencies to create the correct linker order
# TARGET_LINK_LIBRARIES(example-standalone-inferencing-nrf52-zephyr -lstdc++ -lsupc++ -lm -lc -lgcc -lnosys)

	
# set(CODAL_APP_SOURCE_DIR "source")
#add_subdirectory(source/porting/zephyr)

# MACRO(RECURSIVE_FIND_DIR return_list dir pattern)
#     FILE(GLOB_RECURSE new_list "${dir}/${pattern}")
#     SET(dir_list "")
#     FOREACH(file_path ${new_list})
#         GET_FILENAME_COMPONENT(dir_path ${file_path} PATH)
#         SET(dir_list ${dir_list} ${dir_path})
#     ENDFOREACH()
#     LIST(REMOVE_DUPLICATES dir_list)
#     SET(${return_list} ${dir_list})
# ENDMACRO()

# MACRO(RECURSIVE_FIND_FILE return_list dir pattern)
#     FILE(GLOB_RECURSE new_list "${dir}/${pattern}")
#     SET(dir_list "")
#     FOREACH(file_path ${new_list})
#         SET(dir_list ${dir_list} ${file_path})
#     ENDFOREACH()
#     LIST(REMOVE_DUPLICATES dir_list)
#     SET(${return_list} ${dir_list})
# ENDMACRO()

# #Edge impulse SDK include directories
# include_directories(${PROJECT_SOURCE_DIR}/source/edge-impulse-sdk)
# include_directories(${PROJECT_SOURCE_DIR}/source/edge-impulse-sdk/third_party/flatbuffers/include)
# include_directories(${PROJECT_SOURCE_DIR}/source/edge-impulse-sdk/third_party/gemmlowp)
# include_directories(${PROJECT_SOURCE_DIR}/source/edge-impulse-sdk/third_party/ruy)


# #finally, find sources and includes of the application, and create a target.
# RECURSIVE_FIND_DIR(INCLUDE_DIRS "${PROJECT_SOURCE_DIR}/${CODAL_APP_SOURCE_DIR}" "*.h")
# # *.c?? only catches .cpp, not .c, so let's be precise
# RECURSIVE_FIND_FILE(SOURCE_FILES "${PROJECT_SOURCE_DIR}/${CODAL_APP_SOURCE_DIR}" "*.cpp")
# RECURSIVE_FIND_FILE(CC_FILES "${PROJECT_SOURCE_DIR}/${CODAL_APP_SOURCE_DIR}" "*.cc")

# RECURSIVE_FIND_FILE(S_FILES "${PROJECT_SOURCE_DIR}/${CODAL_APP_SOURCE_DIR}" "*.s")
# RECURSIVE_FIND_FILE(C_FILES "${PROJECT_SOURCE_DIR}/${CODAL_APP_SOURCE_DIR}" "*.c")
# list(APPEND SOURCE_FILES ${S_FILES})
# list(APPEND SOURCE_FILES ${C_FILES})
# list(APPEND SOURCE_FILES ${CC_FILES})

# #exclude directories from source files
# set(EXCLUDE_DIR "/utensor/")
# foreach (TMP_PATH ${SOURCE_FILES})
#     string (FIND ${TMP_PATH} ${EXCLUDE_DIR} EXCLUDE_DIR_FOUND)
#     if (NOT ${EXCLUDE_DIR_FOUND} EQUAL -1)
#         list (REMOVE_ITEM SOURCE_FILES ${TMP_PATH})
#     endif ()
# endforeach(TMP_PATH)

# set(EXCLUDE_DIR "/edge-impulse-sdk/porting/")
# foreach (TMP_PATH ${SOURCE_FILES})
#     string (FIND ${TMP_PATH} ${EXCLUDE_DIR} EXCLUDE_DIR_FOUND)
#     if (NOT ${EXCLUDE_DIR_FOUND} EQUAL -1)
#         list (REMOVE_ITEM SOURCE_FILES ${TMP_PATH})
#     endif ()
# endforeach(TMP_PATH)

# set(EXCLUDE_DIR "ei_run_classifier_c")
# foreach (TMP_PATH ${SOURCE_FILES})
#     string (FIND ${TMP_PATH} ${EXCLUDE_DIR} EXCLUDE_DIR_FOUND)
#     if (NOT ${EXCLUDE_DIR_FOUND} EQUAL -1)
#         list (REMOVE_ITEM SOURCE_FILES ${TMP_PATH})
#     endif ()
# endforeach(TMP_PATH)

# get_property(dirs DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY INCLUDE_DIRECTORIES)
# foreach(dir ${dirs})
#   message(STATUS "dir='${dir}'")
# endforeach()
	
target_sources(app PRIVATE src/main.c)

#Include source directory
#zephyr_include_directories(include)



#add specific projec definitions
# add_definitions( -DEIDSP_QUANTIZE_FILTERBANK=0 )
# add_definitions( -DEIDSP_USE_CMSIS_DSP=1 )
# add_definitions( -DEI_CLASSIFIER_TFLITE_ENABLE_CMSIS_NN=1 )
# add_definitions( -DARM_MATH_LOOPUNROLL )