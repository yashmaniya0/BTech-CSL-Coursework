library(shiny)
library(ggplot2)

wine_data <- read.csv("WineQT.csv")

ui <- fluidPage(
  titlePanel("Histogram of pH"),
  sidebarLayout(
    sidebarPanel(
      sliderInput("bins", "Number of bins:", min = 1, max = 50, value = 30),
      sliderInput("quality", "Minimum wine quality:", min = 3, max = 9, value = 5)
    ),
    mainPanel(
      plotOutput("histogram_plot")
    )
  )
)

server <- function(input, output) {
  
  output$histogram_plot <- renderPlot({
    filtered_data <- subset(wine_data, quality >= input$quality)
    ggplot(filtered_data, aes(x = pH)) + 
      geom_histogram(binwidth = 1/input$bins) +
      labs(title = "Histogram of pH", x = "pH", y = "Frequency")
  })
}

shinyApp(ui = ui, server = server)
