#include <stdint.h>
struct gpt_header {
  uint64_t signature;
  uint32_t revision;
  uint32_t header_size;
  uint32_t crc32;
  uint32_t reserved;
  uint64_t current_lba;
  uint64_t backup_lba;
  uint64_t first_usable_lba;
  uint64_t last_usable_lba;
  uint8_t  disk_guid[16];
  uint64_t partition_entry_lba;
  uint32_t num_partition_entries;
  uint32_t size_of_partition_entry;
  uint32_t partition_array_crc32;
};
struct gpt_entry {
  uint8_t  partition_type_guid[16];
  uint8_t  unique_guid[16];
  uint64_t first_lba;
  uint64_t last_lba;
  uint64_t attributes;
  uint16_t name[36];
};
struct sblock {
  uint32_t s_inodes_count;
  uint32_t s_blocks_count_lo;
  uint32_t s_r_blocks_count_lo;
  uint32_t s_free_blocks_count_lo;
  uint32_t s_free_inodes_count;
  uint32_t s_first_data_block;
  uint32_t s_log_block_size;
  uint32_t s_log_cluster_size;
  uint32_t s_blocks_per_group;
  uint32_t s_clusters_per_group;
  uint32_t s_inodes_per_group;
};
struct inode_entry {
  uint32_t inode;
  uint16_t rec_len;
  uint8_t  name_len;
  uint8_t  file_type;
  char     name[];
};