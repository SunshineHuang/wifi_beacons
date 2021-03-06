#ifndef _BSSID_TABLE_H
#define _BSSID_TABLE_H

#define HT_CAP 45
#define HT_INFO  61
#define RSN_INFO  48
#define VENDOR_SPECIFIC 221

struct r_packet {
  char mac_address[18];
  char essid[33] ;
  u_int16_t  freq ;

  u_int8_t db_sig;
  u_int8_t db_noise;

  double dbm_sig; //changed from u_int8_t to double as now these values store the antilog of the signal recieved
  double dbm_noise; 

  float rate; 
  float rate_mcs ;

  float rate_max; 
  u_int8_t antenna;

  u_int8_t bad_fcs_err;
  u_int8_t short_preamble_err;
  u_int8_t radiotap_wep_err;
  u_int8_t frag_err;
  u_int8_t cfp_err ;
  u_int8_t retry ;
  u_int8_t channel;

  u_int8_t n_enabled; // added on 14 feb, 2012

  u_int8_t strictly_ordered;
  u_int8_t pwr_mgmt;
  u_int8_t wep_enc;
  u_int8_t more_frag;
  char channel_info[5];

  u_int8_t cap_privacy ;
  u_int8_t cap_ess_ibss ;

};


typedef struct {
  char mac_add[18];
  char essid[33];

  int packet_count;
  int n_enabled_count; // added on 14 feb, 2012

  int bad_fcs_err_count;
  u_int16_t short_preamble_err_count;
  u_int16_t radiotap_wep_err_count;
  u_int16_t retry_count;
  u_int16_t cfp_err_count ;
  u_int16_t frag_err_count ;
  u_int16_t retry_err_count;
  u_int16_t strictly_ordered_err_count;

  u_int16_t pwr_mgmt_count;
  u_int16_t wep_enc_count;
  u_int16_t more_frag_count;

  double dbm_signal_sum; //changed from float to long double as the values stored are the sum of antilogs and not the dbm values
  double dbm_noise_sum;
  
  u_int8_t db_signal_sum;
  u_int8_t db_noise_sum;

  u_int8_t channel;
  u_int8_t antenna; 
  
  u_int16_t freq;
  
  float rate;
  float rate_mcs ;
  float rate_max; 

  char channel_info[5];

  u_int8_t cap_privacy ;
  u_int8_t cap_ess_ibss ;
  u_int8_t channel_change;

} address_table_entry_t;

#define MAC_TABLE_ENTRIES 255

typedef struct {
  /* A list of MAC mappings. A mapping ID is simply
   * that mapping's index offset into this array. */
  address_table_entry_t entries[MAC_TABLE_ENTRIES];
  /* The index of the first (i.e., oldest) mapping in the list */
  int first;
  /* The index of the last (i.e., newest) mapping in the list */
  int last;
  int length;
  /* The index of the last mapping sent to the server. */
  int added_since_last_update;
} address_table_t;

address_table_t address_table;

#endif /* BSSID_TABLE_H*/
