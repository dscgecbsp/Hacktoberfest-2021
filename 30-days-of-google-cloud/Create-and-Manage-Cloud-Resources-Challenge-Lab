############################ Getting-Started-Create-and-Manage-Cloud-Resources-Challenge-Lab ########################


Task1

gcloud compute instances create nucleus-jumphost \
          --network nucleus-vpc \
          --zone us-east1-b  \
          --machine-type f1-micro  \
          --image-family debian-9  \
          --image-project debian-cloud
          
 --------------------------------------------------------
 
 Task2
 
 Part1


gcloud container clusters create nucleus-backend \
          --num-nodes 1 \
          --network nucleus-vpc \
          --region us-east1
          
          
gcloud container clusters get-credentials nucleus-backend \
          --region us-east1
          
--------------------------------------------------------------
Part2



kubectl create deployment hello-server \
          --image=gcr.io/google-samples/hello-app:2.0
          
---------------------------------------------------------------          
Part3


kubectl expose deployment hello-server \
          --type=LoadBalancer \
          --port 8080

--------------------------------------------------------------

Task3

Part1


cat << EOF > startup.sh
#! /bin/bash
apt-get update
apt-get install -y nginx
service nginx start
sed -i -- 's/nginx/Google Cloud Platform - '"\$HOSTNAME"'/' /var/www/html/index.nginx-debian.html
EOF

----------------------------------------------------------------
Part2

gcloud compute instance-templates create web-server-template \
          --metadata-from-file startup-script=startup.sh \
          --network nucleus-vpc \
          --machine-type g1-small \
          --region us-east1

-----------------------------------------------------------------
Part 3

gcloud compute instance-groups managed create web-server-group \
          --base-instance-name web-server \
          --size 2 \
          --template web-server-template \
          --region us-east1

------------------------------------------------------------------
Part4

gcloud compute firewall-rules create web-server-firewall \
          --allow tcp:80 \
          --network nucleus-vpc

-------------------------------------------------------------------
Part5

          
          
gcloud compute http-health-checks create http-basic-check
gcloud compute instance-groups managed \
          set-named-ports web-server-group \
          --named-ports http:80 \
          --region us-east1

------------------------------------------------------------------
Part6 


gcloud compute backend-services create web-server-backend \
          --protocol HTTP \
          --http-health-checks http-basic-check \
          --global
          
--------------------------------------------------------------------
Part7
          
gcloud compute backend-services add-backend web-server-backend \
          --instance-group web-server-group \
          --instance-group-region us-east1 \
          --global

-------------------------------------------------------------------
Part8

gcloud compute url-maps create web-server-map \
          --default-service web-server-backend
          
          
-------------------------------------------------------------------
Part9
          
          
gcloud compute target-http-proxies create http-lb-proxy \
          --url-map web-server-map

-------------------------------------------------------------------
Part 10


gcloud compute forwarding-rules create http-content-rule \
        --global \
        --target-http-proxy http-lb-proxy \
        --ports 80
gcloud compute forwarding-rules list
