const credentials = {
    apiKey:'7b096f3098087abbc58d328376e591229fd908d043cb5cca7f409f53adb95c39',
    username:'ujumbehealth',
  };
  
  const africastalking = require("africastalking")(credentials);
  
  
  async function sendSms() {
      try {
          const phone = "+254721333151";
          //const internationalPhone = +254${phone};
          // console.log(credentials);
          const result = await africastalking.SMS.send({
          to: phone,
          message: "Hello, this is a test message from Me!!.",
          //from: "GASENTYNEL",
          });
          console.log(result);
      } catch (err) {
          console.log(err);
      }
      }
  
      // custom function to send sms after 5 seconds
  function Timer() {
      setTimeout(() => {
          sendSms();
      }, 5000); 
  }
  
  Timer();