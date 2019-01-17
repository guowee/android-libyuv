package com.yuv.util;

public class YUVUtil {

    static {
        System.loadLibrary("yuv-util");
    }

    public static native void ARGBToI420(byte[] src_argb, int src_stride_argb,
                                         byte[] dst_y, int dst_stride_y,
                                         byte[] dst_u, int dst_stride_u,
                                         byte[] dst_v, int dst_stride_v,
                                         int width, int height);

    //将yuv数据转为argb
    public static native void convertToARGB(byte[] src_frame, int src_size,
                                            byte[] dst_argb, int dst_stride_argb,
                                            int crop_x, int crop_y,
                                            int src_width, int src_height,
                                            int crop_width, int crop_height,
                                            int rotation,
                                            int format);


}
