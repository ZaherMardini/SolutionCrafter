<?php
$prices = [2,9,1,3];
function maxProfit($prices) {
  $mn = $prices[0];
  $mx = $prices[1];
  $mxIndex = 1;
  $mnIndex = 0;
  foreach ($prices as $key => $price) {
    // find the max from the second element
    if($price !== $prices[0]){
      // set the max with its order
      if($price > $mx){
        $mx = $price;
        $mxIndex = $key;
      }
    }
    // find the min and the order is less than the max
    if($price <= $mn && $mnIndex < $mxIndex){
      // var_dump($price, $mx, $mxIndex, $mn, $mnIndex);
      $mn = $price;
      $mnIndex = $key;
    }
  }
  var_dump($mx, $mxIndex, $mn, $mnIndex);
}
echo maxProfit($prices);
