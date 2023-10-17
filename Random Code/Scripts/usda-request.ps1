curl -X "GET" ^
  "https://api.nal.usda.gov/fdc/v1/foods/search?api_key=DEMO_KEY&query=Mc&dataType=Branded&pageSize=2&pageNumber=1" ^
  -H "accept: application/json"