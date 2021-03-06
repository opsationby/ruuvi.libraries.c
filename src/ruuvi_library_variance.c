// See header file for copyright etc.

#include "ruuvi_library_variance.h"
#include <float.h>
#include <math.h>

float ruuvi_library_variance (const float * const data, const size_t data_length)
{
    float rvalue = NAN;

    if (NULL == data || 0 == data_length) { return NAN; }

    float delta_sum = 0;
    float mean = 0;

    // Calculate mean of values
    for (size_t ii = 0; ii < data_length; ii++)
    {
        if (!isfinite (data[ii])) { return NAN; }

        mean += data[ii];
    }

    mean /= data_length;

    // Calculate squared differences
    for (size_t ii = 0; ii < data_length; ii++)
    {
        delta_sum += powf (data[ii] - mean, 2);
    }

    // mean of differences
    if (!isfinite (delta_sum)) { return NAN; }

    rvalue = delta_sum / data_length;
    return rvalue;
}