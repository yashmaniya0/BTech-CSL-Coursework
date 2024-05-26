library(shiny)
library(readr)

# Load the dataset
wine_data <- read_csv("WineQT.csv")

# Define UI
ui <- fluidPage(
  titlePanel("Interactive Filter on pH"),
  sidebarLayout(
    sidebarPanel(
      sliderInput("ph", "pH:",
                  min = min(wine_data$pH),
                  max = max(wine_data$pH),
                  value = c(min(wine_data$pH), max(wine_data$pH)),
                  step = 0.1)
    ),
    mainPanel(
      plotOutput("histogram")
    )
  )
)

# Define server logic
server <- function(input, output) {
  output$histogram <- renderPlot({
    filtered_data <- wine_data[wine_data$pH >= input$ph[1] & wine_data$pH <= input$ph[2], ]
    hist(filtered_data$pH, main = "Histogram of pH", xlab = "pH")
  })
}

# Run the application
shinyApp(ui = ui, server = server)
