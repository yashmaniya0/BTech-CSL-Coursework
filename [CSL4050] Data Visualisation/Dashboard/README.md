## **Sale Analytics Dashboard**

This R-Shiny dashboard provides an interactive interface for analyzing sales data from shopping world of Istanbul! It includes various tabs to explore different aspects of sales analytics.


### **Purpose**
The purpose of this dashboard is to provide an interactive platform for analyzing sales data from various shopping malls in Istanbul, Turkey. It aims to enable users to explore sales trends, distribution across categories, demographic insights, and payment method preferences to **facilitate data-visualization-driven decision-making in sales strategies**.

### **Features**
- **Main Dashboard Tab**: Quick navigations to other tabs showing shopping mall sales in Istanbul, Turkey.
- **Overall Sales Analysis**: Explore monthly sales and sales by location.
- **Category Wise Sales**: Analyze sales distribution across different categories.
- **Gender & Age Sales Analysis**: Dive into sales analysis by gender and age groups.
- **Payment Method Analysis**: Analyze sales based on payment methods.


### **Plots Used**
* **Overall Sales Analysis:** Monthly sales bar plot and sales by location bar plot.
* **Category Wise Sales:** Pie chart showing sales distribution across different categories.
* **Gender & Age Sales Analysis:** Violin plot showing sales by gender as well as multi-bar plot for age-sales analysis.
* **Payment Method Analysis:** Bar plot and pie chart showing sales based on payment methods.


### **Running the Dashboard**
To run the Sale Analytics Dashboard:

1. Ensure you have R and RStudio installed on your machine.
2. Install the required packages by running the following command in RStudio:
    ```R
    install.packages(c("shiny", "shinydashboard", "plotly", "dplyr", "ggridges"))
    ```
3. Download the dataset "customer_shopping_data.csv" and place it in the same directory as the app script.
4. Run the script `app.R` by clicking the "Run App" button or by pressing Ctrl + Shift + Enter.
5. The dashboard should open in your default web browser. If not, check the RStudio console for the URL to access the dashboard.
6. Explore the various tabs to analyze the sales data interactively.