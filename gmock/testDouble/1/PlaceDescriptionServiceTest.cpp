#include "gmock/gmock.h"

#include "PlaceDescriptionService.h"
#include "Http.h"

using namespace std;
using namespace testing;

class APlaceDescriptionService: public Test {
public:
   static const string ValidLatitude;
   static const string ValidLongitude;
};

const string APlaceDescriptionService::ValidLatitude("38.005");
const string APlaceDescriptionService::ValidLongitude("-104.44");

class HttpStub: public Http {
public:
   MOCK_METHOD0(initialize, void());
   MOCK_CONST_METHOD1(get, string(const string&));
};

class PlaceDescriptionService_StubHttpService: public PlaceDescriptionService {
public:
   PlaceDescriptionService_StubHttpService(shared_ptr<HttpStub> httpStub) 
      : httpStub_{httpStub} {}
   shared_ptr<Http> httpService() const override { return httpStub_; }
   shared_ptr<Http> httpStub_;
};

TEST_F(APlaceDescriptionService, MakeHttpRequestToObtainAddress) {
   InSequence forceExpectationOrder;

   shared_ptr<HttpStub> httpStub{new HttpStub};

   string urlStart{
      "http://open.mapquestapi.com/nominatim/v1/reverse?format=json&"};

   auto expectedURL = urlStart + 
      "lat=" + APlaceDescriptionService::ValidLatitude + "&" +
      "lon=" + APlaceDescriptionService::ValidLongitude;

   // Predict the input to Mock object !!!
   // According to TDD, this test should be written first before the 
   // implementation of the method summaryDescription.
   EXPECT_CALL(*httpStub, initialize());
   EXPECT_CALL(*httpStub, get(expectedURL));

   PlaceDescriptionService_StubHttpService service{httpStub};

   auto description = service.summaryDescription(ValidLatitude, ValidLongitude);
}

TEST_F(APlaceDescriptionService, FormatsRetrievedAddressIntoSummaryDescription) {
   // The NiceMock template effectively tells Google Mock to track interactions
   // only for methods on which expectations exist.
   shared_ptr<HttpStub> httpStub{new NiceMock<HttpStub>};

   // Set the output of the Mock object !!!
   // This test also should be written before the implementation
   // of the method summaryDescription.
   EXPECT_CALL(*httpStub, get(_))
      .WillOnce(Return(
         R"({ "address": {
              "road":"Drury Ln",
              "city":"Fountain",
              "state":"CO",
              "country":"US" }})"));
   PlaceDescriptionService_StubHttpService service(httpStub);

   auto description = service.summaryDescription(ValidLatitude, ValidLongitude);
   ASSERT_THAT(description, Eq("Drury Ln, Fountain, CO, US"));
}
