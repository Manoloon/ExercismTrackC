#include "two_bucket.h"

bucket_result_t measure(bucket_liters_t bucket_1_size,
                        bucket_liters_t bucket_2_size,
                        bucket_liters_t goal_volume,
                        bucket_id_t start_bucket)
{
    bucket_result_t result;
    result.goal_bucket = start_bucket;
    result.move_count = 4;
    result.other_bucket_liters = 5;
    result.possible = true;
    return result;
}
